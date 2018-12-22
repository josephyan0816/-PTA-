#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode *Tree;
struct TreeNode
{
	int v;
	Tree left,right;
	int flag;
};
Tree MakeTree(int n);
Tree Insert(Tree T,int v);
Tree NewNode(int v);
int check(Tree T,int v);
int Judge(Tree T,int n);
void ResetTree(Tree T);
void FreeTree(Tree T);
int main()
{
	Tree T;
	int n,L,i;
	scanf("%d",&n);
	while(n)
	{
		scanf("%d",&L);
		T=MakeTree(n);
		for(i=0;i<L;i++)
		{
			if(Judge(T,n))printf("Yes\n");
			else printf("No\n");
			ResetTree(T);
		}
		FreeTree(T);
		scanf("%d",&n);
	}
	return 0;
}
Tree MakeTree(int n)
{
	Tree T;
	int i,v;
	scanf("%d",&v);
	T=NewNode(v);
	for(i=1;i<n;i++)
	{
		scanf("%d",&v);
		T=Insert(T,v);
	}
	return T;
}
Tree Insert(Tree T,int v)
{
	if(T==NULL)T=NewNode(v);
	else{
		if(v>T->v)
			T->right=Insert(T->right,v);
		else
			T->left=Insert(T->left,v);	
	}
	return T;
}
Tree NewNode(int v)
{
	Tree T=(Tree)malloc(sizeof(struct TreeNode));
	T->v=v;
	T->left=NULL;
	T->right=NULL;
	T->flag=0;
	return T;
}
int check(Tree T,int v)
{
	if(T->flag!=0)
	{
		if(v<T->v)return check(T->left,v);
		else if(v>T->v)return check(T->right,v);
		else return 0;
	}
	else
	{
		if(v==T->v)
		{
			T->flag=1;
			return 1;
		}
		else return 0;
	}
}
int Judge(Tree T,int n)
{
	int i,v,flag=0;
	scanf("%d",&v);
	if(v!=T->v)flag=1;
	else T->flag=1;
	for(i=1;i<n;i++)
	{
		scanf("%d",&v);
		if((flag==0)&&(check(T,v)==0))flag=1;
		
	}
	if(flag)return 0;
	else return 1;
}
void ResetTree(Tree T)
{
	if(T->left) ResetTree(T->left);
	if(T->right) ResetTree(T->right);
	T->flag=0;
}
void FreeTree(Tree T)
{
	if(T->left) FreeTree(T->left);
	if(T->right) FreeTree(T->right);
	free(T);
}
