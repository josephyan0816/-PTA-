#include<stdio.h>
#include<stdlib.h>
#define MAXN 10
int visit[MAXN];
int G[MAXN][MAXN];
void DFS(int i,int N);
void BFS(int i,int N);

int main()
{
	int N,E,i,x,y;
	scanf("%d %d",&N,&E);
	for(int j=0;j<MAXN;j++)
	{
		visit[j]=0;
	}
	for(i=0;i<E;i++)
	{
		scanf("%d %d",&x,&y);
		G[x][y]=1;
		G[y][x]=1;
	}
	for(i=0;i<N;i++)
	{
		if(visit[i]==0)
		{
			printf("{");
			DFS(i,N);
			printf(" }\n");
			
		}
	}
	for(int j=0;j<MAXN;j++)
	{
		visit[j]=0;
	}
	for(i=0;i<N;i++)
	{
		if(visit[i]==0)
		{
			printf("{");
			BFS(i,N);
			printf(" }\n");
		}
	}
	
}
void DFS(int i,int N)
{
	int j;
	visit[i]=1;
	printf(" %d",i);
	for(j=0;j<N;j++)
	{
		if(visit[j]==0&&G[i][j])
		{
			DFS(j,N);
		}
	}
	
	
}
void BFS(int i,int N)
{
	int queue[MAXN],v,rear,front,j;
	rear=-1;
	front=-1;
	visit[i]=1;
	queue[++rear]=i;
	while(front<rear)
	{
		v=queue[++front];
		printf(" %d",v);
		for(j=0;j<N;j++)
		{
			if(visit[j]==0&&G[v][j])
			{
				visit[j]=1;
				queue[++rear]=j;
			}
		}
	}
}
