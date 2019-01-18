#include<stdio.h>
#include<math.h>

int a[1001],T[1001];

void solve(int Aleft,int Aright,int Troot);
int getLeftLength(int n);


int main()
{
	int i,j,t,n;
	int flag=1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(j=1;j<n;j++)
	{
		for(i=0;i<n-j;i++)
		{
			if(a[i]>a[i+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		}
	}
	solve(0,n-1,0);
	for(i=0;i<n;i++)
	{
		if(flag)
		{
			printf("%d",T[i]);
			flag=0;
		}
		else
		{
			printf(" %d",T[i]);
		}
	}
	
}
void solve(int Aleft,int Aright,int Troot)
{
	int n,L;
	int Leftroot,Rightroot;
	n=Aright-Aleft+1;
	if(n==0)return;
	L=getLeftLength(n);
	T[Troot]=a[Aleft+L];
	//根节点放在0里面，从0开始算下标
	 Leftroot=Troot*2+1;
	 Rightroot=Leftroot+1;
	 solve(Aleft,Aleft+L-1,Leftroot);
	 solve(Aleft+L+1,Aright,Rightroot);
	
}
int getLeftLength(int n)
{
	int h,x;
	int L;
	h=(int)(log(n+1)/log(2));//向下取整 
	x=n-(pow(2,h)-1);
	if(x>pow(2,h-1))
	{
		x=pow(2,h-1);
	}
	L=pow(2,h-1)-1+x;
	return L;	
}
