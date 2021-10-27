#include <stdio.h>
#include <stdlib.h>

#define Maxsize 30

void Initarry(int map[100][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
}

void Initarry2(int map[2][2], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
}

struct sstack
{
	int top;
	int index[Maxsize][2];
};
typedef struct sstack *Stack;

Stack InitStack()
{
	Stack stack = (Stack)malloc(sizeof(struct sstack));
	if (!stack)
	{
		printf("Alloc Faile");
	}
	stack->top = 0;
	return stack;
}

void PullStack(Stack Pstack, int x, int y)
{
	Pstack->index[++Pstack->top][0] = x;
	Pstack->index[Pstack->top][1] = y;
	if (Pstack->top == Maxsize)
	{
		printf("Over Full!");
	}
}
void PushStack(Stack Pstack)
{
	Pstack->top--;
}

void PassMaze(Stack Pstack, int map[100][100], int step[8][2], int Begin_EN[2][2])
{
	int m;
	int x = Begin_EN[0][0];
	int y = Begin_EN[0][1];
	PullStack(Pstack, x, y);
	while (x != Begin_EN[1][0] || y != Begin_EN[1][1])
	{
		for (m = 0; m < 8; m++)
		{
			if (map[x + step[m][0]][y + step[m][1]] == 0)
			{
				x += step[m][0];
				y += step[m][1];
				PullStack(Pstack, x, y);
				map[x][y] = 2;
				break;
			}
		}
		if (m == 8)
		{
			map[x][y] = 1;
			PushStack(Pstack);
			x = Pstack->index[Pstack->top][0];
			y = Pstack->index[Pstack->top][1];
		}
	}
	printf("%d %d;", x, y);
}
void PrintStack(Stack stack)
{
	stack->top--;
	while (stack->top)
	{
		printf("%d %d;", stack->index[stack->top][0], stack->index[stack->top][1]);
		stack->top--;
	}
}

int main()
{
	int n;
	// int step[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1},{ 0, -1}, {1, -1}};
	int step[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
	scanf("%d", &n);
	int map[100][100];
	Initarry(map, n);
	int Begin_End[2][2];
	Initarry2(Begin_End, 2);

	Stack Pstack = InitStack();

	PassMaze(Pstack, map, step, Begin_End);

	PrintStack(Pstack);

	return 0;
}