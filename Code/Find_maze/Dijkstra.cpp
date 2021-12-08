#include <stdio.h>
#define INF 10000000
#define MaxSize 50
int graph[MaxSize][MaxSize];  //MaxSize为最大顶点数
int dis[MaxSize];             //dis[i]为源点到顶点i的最短距离
int visit[MaxSize];            //visit[i]标记顶点i的最短路径是否已求出visit[i] == 1表示已求出
int prevetrix[MaxSize];       //前驱动点
void dij(int n)
{    
    int count = 0;          //count是已求出最短路径的顶点数目
    visit[0] = 1;    
    prevetrix[0] = 0;    
    count++;    
    for (int i = 1; i < n; i++)    //初始化
    {        
        dis[i] = graph[0][i];        
        prevetrix[i] = 0;    
    }    
    while (count < n)    
    {        
        int min = INF, target_index;        
        for (int i = 1; i < n; i++)        
        {            
            if (visit[i] == 0 && min > dis[i])         //找到距离源点最短的顶点target_index
            {                
                min = dis[i];                
                target_index = i;            
            }        
        }        
        visit[target_index] = 1;        
        count++;        
        for (int i = 1; i < n; i++)        
        {            
            if (visit[i] == 0 && dis[target_index] + 
            graph[target_index][i] < dis[i])            //更新
            {                
                dis[i] = dis[target_index] + graph[target_index][i];
                prevetrix[i] = target_index;            
            }        
        }    
    }
}
int main()
{    
    int n, m;    
    scanf("%d %d", &n, &m);    
    int a, b, w, path[n];    
    for (int i = 0; i < n; i++)    
    {        
        for (int j = 0; j < n; j++)        
        {            
            graph[i][j] = INF;        
        }    
    }    
    for (int i = 0; i < m; i++)    
    {        
        scanf("%d %d %d", &a, &b, &w);        
        graph[a][b] = w;    
    }     
    dij(n);    
    printf("\n\n");    
    for (int i = 1; i < n; i++)    
    {        
        if (dis[i] == INF)        
        {            
            printf("顶点0到顶点%d没有最短路径\n", i);        
        }        
        else        
        {            
    	    printf("顶点0到顶点%d有长为%d的最短路径：", i,dis[i]);            
    	    int cur = i, index = 0;            
            path[index] = cur;            
            while (1)            
            {                
                path[index + 1] = prevetrix[path[index]];                
                if (path[index + 1] == 0)                    
                    break;                
                index++;            
            }            
            for (int j = index + 1; j > 0; j--)            
            {                
                printf("%d->", path[j]);            
            }            
            printf("%d\n", path[0]);        
        }    
    }
}