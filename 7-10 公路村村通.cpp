#include<stdio.h>
#include<stdlib.h>
#define INFINITY 65535
#define MAXVERTEX 1001
//#define ERROR -1
int Nv,Ne,G[MAXVERTEX][MAXVERTEX];
void CreateGraph();
int Prim();



int main()
{
	
	int f=0;
	scanf("%d %d",&Nv,&Ne);
	CreateGraph();
	f=Prim();
	printf("%d",f);
	
	
	
}
void CreateGraph()
{
	int i,j;
	int v1,v2,w;
	for(i=1;i<=Nv;i++)
	{
		for(j=1;j<=Nv;j++)
		{
			G[i][j]=INFINITY;
		}
	}
	for(i=0;i<Ne;i++)
	{
		scanf("%d %d %d",&v1,&v2,&w);
		G[v1][v2]=w;
		G[v2][v1]=G[v1][v2];
		
	}
	
}
int Prim()
{
	int min;
	int i,j,k;
	int lowcost[MAXVERTEX];
	int cost=0;
	lowcost[1]=0;
	
	for(i=2;i<=Nv;i++)
	{
		lowcost[i]=G[1][i];
	}
	
	for(i=2;i<=Nv;i++)
	{
		min=INFINITY;
		j=1;
		k=0;
		
		while(j<=Nv)
		{
			if(lowcost[j]!=0&&lowcost[j]<min)
			{
				min=lowcost[j];
				k=j;
				
			}
			j++;
		}
		if(k==0)
		{
			return -1;
		}
		cost=cost+min;
		lowcost[k]=0;
		for(j=2;j<=Nv;j++)
		{
			if(lowcost[j]!=0&&G[k][j]<lowcost[j])
			{
				lowcost[j]=G[k][j];
			}
		}
		
		
	}
	
	return cost;
	
}
