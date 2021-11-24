#include <stdio.h>
#include <stdlib.h>

//��ջ���Ͷ��� 
typedef int DataType;
struct Node
{
	DataType data;
	struct Node* next;
};

struct Maze
{
	DataType data[100][100];
	int size;
}; 

typedef struct Node *PNode;
typedef struct Node *top, *LinkStack;

//������ջ
LinkStack SetNullStack_Link()
{
	LinkStack top =(LinkStack)malloc(sizeof(struct Node));
	if (top != NULL)
		top->next = NULL;
	else 
		 printf("Alloc failure");
	return top;
 } 

//�ж�ջ��

int IsNullStack_link(LinkStack top)
{
	if(top->next == NULL)
		return 1;
	else 
		return 0;
 } 
 
 //��ջ
 
void Push_link(LinkStack top,DataType x)
{
	PNode p;
	p = (PNode)malloc(sizeof(struct Node));
	if(top == NULL)
		printf("Alloc failure");
	else
	{
		p->data = x;
		p->next = top->next;
		top->next = p;
	}	
 } 
 
 //��ջ
 
void Pop_link(LinkStack top)
 {
 	PNode p;
 	if(IsNullStack_link(top))
 	{
 		printf("it is empty stack!");
	 }
	 else{
	 p = top->next;
	 top->next = p->next;
	 free(p);	
	 }
	 
  } 


//ȡ����Ԫ��

DataType Top_link(LinkStack top)
{
	if(IsNullStack_link(top))
		printf("it is empty stack!");
	else 
		return top->next->data;
 } 


// 
int MazeDFS(int entryX,int entryY,int exitX,int exitY,Maze maze)
{
	
	int direction[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	LinkStack linkStackX = NULL;
	LinkStack linkStackY = NULL;
	int posX,posY;
	int preposX,preposY;
	int **mark;
	int i,j;
	int mov;
	
	mark = (int**)malloc(sizeof(int*) * maze.size);
	for(i=0;i<maze.size;i++)
		mark[i]=(int*)malloc(sizeof(int)*maze.size);
	for(i=0;i<maze.size;i++)
	{
		for(j=0;j<maze.size;j++)
			mark[i][j]=0;
	}
	linkStackX = SetNullStack_Link();
	linkStackY = SetNullStack_Link();
	mark[entryX][entryY] = 1;
	Push_link(linkStackX,entryX);
	Push_link(linkStackY,entryY);
	while(!IsNullStack_link(linkStackX))
	{
		preposX = Top_link(linkStackX);
		preposY = Top_link(linkStackY);
		Pop_link(linkStackX);
		Pop_link(linkStackY);
		mov = 0;
		while(mov<4)
		{
			posX = preposX + direction[mov][0];
			posY = preposY + direction[mov][1];
			if(posX == exitX && posY == exitY)
			{
				Push_link(linkStackX,preposX);
				Push_link(linkStackY,preposY);
				//printf("��������Թ�·�����£�\n");
				printf("%d %d;",exitX,exitY);
				while(!IsNullStack_link(linkStackX))
				{
					posX = Top_link(linkStackX);
					posY = Top_link(linkStackY);
					Pop_link(linkStackX);
					Pop_link(linkStackY);
					printf("%d %d;",posX,posY);
				}  
				return 1;
			}
		if(maze.data[posX][posY] == 0 && mark[posX][posY]==0)
		{
			mark[posX][posY] = 1;
			Push_link(linkStackX,preposX);
			Push_link(linkStackY,preposY);
			preposX = posX;
			preposY = posY;
			mov = 0;
		
		}
		else
			mov++;
		}
		
	}
	return 0;
	
} 


int main()
{
	int size,exitX,exitY,entryY,entryX;
	Maze maze;
	scanf("%d",&maze.size);
	for(int i=0;i<maze.size;i++){
		for(int j=0;j<maze.size;j++){
			scanf("%d",&maze.data[i][j]);
		}
	}
	scanf("%d%d%d%d",&entryX,&entryY,&exitX,&exitY);

	MazeDFS(entryX,entryY,exitX,exitY,maze);
	
}




 
