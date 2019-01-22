#include<stdio.h>
#include<stdlib.h>

#define MAXVERTEX 500
#define INFINITY 65536

void CreateGraph();
void Dijkstra(int v);

int G[MAXVERTEX][MAXVERTEX][2];
int cost[MAXVERTEX];
int distance[MAXVERTEX];
int Ne,Nv;
int visit[MAXVERTEX];



int main()
{
	
	int S,D;
	scanf("%d %d %d %d",&Nv,&Ne,&S,&D);
	CreateGraph();
	Dijkstra(S);
	if(distance[D]<INFINITY)
	{
		printf("%d %d",distance[D],cost[D]);
	}
	
	
}
void CreateGraph()
{
	int i,j;
	int v1,v2;
	int dis,cos;
	for(i=0;i<Nv;i++)
	{
		for(j=0;j<Nv;j++)
		{
			G[i][j][0]=INFINITY;
			G[i][j][1]=INFINITY;
			
		}
	}
	for(i=0;i<Ne;i++)
	{
		scanf("%d %d %d %d",&v1,&v2,&dis,&cos);
		G[v1][v2][0]=G[v2][v1][0]=dis;
		G[v1][v2][1]=G[v2][v1][1]=cos;
	}
}


void Dijkstra( int v)
{
    //求从v结点到其他各结点的最短距离
    int i,j,k;
    int min,c;

    for( i=0; i<Nv; i++)
    {
        visit[i] =0;
        distance[i] =G[v][i][0];   //将与v点有连接的结点加上距离
        cost[i] =G[v][i][1];
    }

    visit[v] = 1;
    distance[v] =0;   //V到V距离为0
    cost[v] = 0;

    for( i=1; i<Nv; i++)
    {
        min = INFINITY;     //当前所知离v结点的最近距离
        for( j=0; j<Nv; j++)
        {
            //寻找离v结点的最近距离
            if( !visit[j] && distance[j]<min)
            {
                k = j;
                min = distance[j];
                c = cost[j];
            }
        }

        visit[k] = 1;
        for( j=0; j<Nv; j++)
        {
            //修正最短路径和距离
            if( !visit[j] && (min+G[k][j][0]<distance[j]))
            {
                distance[j] = min+G[k][j][0];
                cost[j] = c + G[k][j][1];

            }
            else if( !visit[j] && (min+G[k][j][0]==distance[j]) && (c+G[k][j][1] < cost[j]))
            {

                cost[j] = c + G[k][j][1];  
            }
        }

    }

}
