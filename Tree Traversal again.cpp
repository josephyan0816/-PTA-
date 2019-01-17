#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxN 35
//#define ElementType int

typedef struct SNode *Stack;
struct SNode{
	int *Data;
	int top;
	int MaxSize;
	
};

int pre[MaxN],in[MaxN],post[MaxN];
Stack CreateStack(int MaxSize);
void Push(Stack PtrS,int X);
int Pop(Stack PtrS);
void solve(int preL,int inL,int postL,int n);


int main()
{
	
	int i,j,k,x,N;
		j=0;
		k=0;
		int flag=1;
		char str[10];
		scanf("%d",&N);
		Stack s=CreateStack(N);
		for(i=0;i<2*N;i++)
		{
			scanf("%s",str); 
			if(strcmp(str,"Push")==0)
			{
				scanf("%d",&x);
				pre[j++]=x;
				Push(s,x);
			}
			else
			{
				in[k++]=Pop(s);
			}
			
		}	
	solve(0,0,0,N);
	for(i=0;i<N;i++)
	{
		if(flag)
		{
			flag=0;
			printf("%d",post[i]);
			
		}
		else
		{
			printf(" %d",post[i]);
		}
	}
	
}
void solve(int preL,int inL,int postL,int n)
{
	int i,root;
	int L,R;
	if(n==0)return ;
	if(n==1)
	{
		post[postL]=pre[preL];
		return;
	}
	root=pre[preL];
	post[postL+n-1]=root;
	for(i=0;i<n;i++)
		if(in[inL+i]==root)break;
	L=i;
	R=n-L-1;
	solve(preL+1,inL,postL,L);
	solve(preL+L+1,inL+L+1,postL+L,R);
}
Stack CreateStack(int MaxSize)
{
	Stack S=(Stack)malloc(sizeof(struct SNode));
	S->Data=(int*)malloc(MaxSize*sizeof(int));
	S->top=-1;
	S->MaxSize=MaxSize;
	return S;
	
}
void Push(Stack S,int X)
{
	if(S->top==S->MaxSize-1){
		printf("¶ÑÕ»Âú");
	}
	else
	{
		S->Data[++(S->top)]=X;
	}
}
int Pop(Stack S)
{
	if(S->top==-1)
	{
		printf("¿ÕÕ»");
		return -1; 
	}
	else{
		return S->Data[(S->top)--];
	}
}
