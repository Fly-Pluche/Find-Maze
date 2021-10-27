#include <stdio.h>
#include <stdlib.h>

#define Maxsize 300

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

struct queue
{
    int rear;
    int front;
    int index[Maxsize][3];
};
typedef struct queue *Squeue;

Squeue InitQueue()
{
    Squeue stack = (Squeue)malloc(sizeof(struct queue));
    if (!stack)
    {
        printf("Alloc Faile");
    }
    stack->rear = 0;
    stack->front = 0;
    return stack;
}

void EnQueue(Squeue Pstack, int x, int y, int pre)
{
    Pstack->index[++Pstack->rear][0] = x;
    Pstack->index[Pstack->rear][1] = y;
    Pstack->index[Pstack->rear][2] = pre;
    if (Pstack->rear == Maxsize)
    {
        printf("Over Full!");
    }
}
void DeQueue(Squeue Pstack, int *x, int *y)
{
    Pstack->front++;
    *x = Pstack->index[Pstack->front][0];
    *y = Pstack->index[Pstack->front][1];
}

void PassMaze(Squeue Pstack, int map[100][100], int step[8][2], int Begin_EN[2][2])
{
    int m;
    int x = Begin_EN[0][0];
    int y = Begin_EN[0][1];
    Pstack->index[0][1] = -1;
    EnQueue(Pstack, x, y, -1);

    while (x != Begin_EN[1][0] || y != Begin_EN[1][1])
    {
        DeQueue(Pstack, &x, &y);
        map[x][y] = 2;

        for (m = 0; m < 8; m++)
        {
            if (map[x + step[m][0]][y + step[m][1]] == 0)
            {
                EnQueue(Pstack, x + step[m][0], y + step[m][1], Pstack->front);
                map[x + step[m][0]][y + step[m][1]] = 2;
            }
        }
    }
}
void PrintQueue(Squeue stack, int pos)
{
    int Pos = pos;
    while (Pos != -1)
    {
        printf("%d %d;", stack->index[Pos][0], stack->index[Pos][1]);
        Pos = stack->index[Pos][2];
    }
}

int main()
{
    int n;
    int step[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    scanf("%d", &n);
    int map[100][100];
    Initarry(map, n);
    int Begin_End[2][2];
    Initarry2(Begin_End, 2);

    Squeue Pstack = InitQueue();

    PassMaze(Pstack, map, step, Begin_End);

    PrintQueue(Pstack, Pstack->rear--);

    return 0;
}