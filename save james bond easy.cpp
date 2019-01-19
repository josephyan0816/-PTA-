#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define false 0;
#define true 1;
struct Node{
	double x,y;
	
}pos[101];
int visit[101];
int N;
double D;
const double r=7.5;
int firstjump(int i);
int jump(int v,int i);
int issafe(int v);
int DFS(int v);


int main()
{
	int isjump;
	scanf("%d %lf",&N,&D);
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%lf %lf",&pos[i].x,&pos[i].y);
	}
	for(i=0;i<N;i++)
	{
		visit[i]=false;
	}
	for(i=0;i<N;i++)
	{
		if(!visit[i]&&firstjump(i))
		{
			isjump=DFS(i);
			if(isjump)break;
		}
	}
	if(isjump)
	{
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	
}
int firstjump(int i)
{
	return (sqrt(pos[i].x*pos[i].x+pos[i].y*pos[i].y))<=D+r;
}
int jump(int v,int i)
{
	return sqrt(abs(pos[v].x-pos[i].x)*abs(pos[v].x-pos[i].x)+abs(pos[v].y-pos[i].y)*abs(pos[v].y-pos[i].y))<=D;
}
int issafe(int v)
{
	return(abs(pos[v].x)>=50-D||abs(pos[v].y>=50-D));
}
int DFS(int v)
{
	visit[v]=true;
	if(issafe(v))
	{
		return true;
	}
	else{
		for(int i=0;i<N;i++)
		{
			if(!visit[i]&&jump(v,i))
			{
				int isjump=DFS(i);
				if(isjump)
				{
					return true;
				}
			}
		}
		
	}
	return false;
	
}



