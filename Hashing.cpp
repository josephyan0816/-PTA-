#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct HNode{
	int *List;
	int Size;
};
typedef struct HNode* HashTable;
int prime[100000];
void is_Prime()
{
	int i,j;
	for(i=0;i<100000;i++)
	{
		prime[i]=1;
	}
	prime[0]=prime[1]=0;
	for(i=2;i<100000;i++)
	{
		if(prime[i])
		{
			for(j=i+i;j<100000;j=j+i)
			{
				prime[j]=0;
			}
			}	
	
	}
		
}
int NextPrime(int n)
{
	if(!prime[n])
	{
		int i=n+1;
		while(!prime[i])
		{
			i++;
		}
		return i;
	}
}

HashTable Create(int n)
{
	HashTable H;
	int i;
	H=(HashTable)malloc(sizeof(struct HNode));
	H->Size=NextPrime(n);
	H->List=(int*)malloc(sizeof(int)*H->Size);
	for(i=0;i<H->Size;i++)
	{
		H->List[i]=0;
	}
	return H;
}

int Insert(HashTable H,int num)
{
	int pos,i;
	pos=num%H->Size;
	for(i=0;i<=H->Size&&H->List[pos];i++)
	{
		pos=(pos+2*i+1)%H->Size;
	}
	if(i<=H->Size)
	{
		H->List[pos]=1;
		return pos;
	}
	else return -1;
	
}
int main()
{
	is_Prime();
	int i,n,m,num;
	int pos[10001];
	HashTable H;
	scanf("%d%d",&m,&n);
	H=Create(m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		pos[i]=Insert(H,num);
		
	}
	if(n)
	{
		printf("%d",pos[0]);
		for(i=1;i<n;i++)
		{
			if(pos[i]==-1)printf(" -");
			else printf(" %d",pos[i]);
		}
	}
}

