#include<stdio.h>
#include<stdlib.h>

#define MaxSize 100001


typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MaxSize];
//typedef struct{
//	ElementType Data;
//	int Parent;
//}SetType;

void Initialization(SetType S,int n);
void Input_connection(SetType S);
void Check_connection(SetType S);
void Check_network(SetType S,int n);
SetName Find(SetType S,ElementType X);
void Union(SetType S,SetName Root1,SetName Root2);




int main()
{
	SetType S;
	int n;
	char op;
	scanf("%d\n",&n);
	Initialization(S,n);
	do{
		scanf("%c",&op);
		switch(op)
		{
			case 'I':Input_connection(S);break;
			case 'C':Check_connection(S);break;
			case 'S':Check_network(S,n);break;
		}
	}while(op!='S');
}
void Initialization(SetType S,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		S[i]=-1;
		}	
}
void Input_connection(SetType S)
{
	ElementType u,v;
	SetName Root1,Root2;
	scanf("%d %d\n",&u,&v);
	Root1=Find(S,u-1);
	Root2=Find(S,v-1);
	if(Root1!=Root2)
	Union(S,Root1,Root2);
}
void Check_connection(SetType S)
{
	ElementType u,v;
	SetName Root1,Root2;
	scanf("%d %d\n",&u,&v);
	Root1=Find(S,u-1);
	Root2=Find(S,v-1);
	if(Root1==Root2)
		printf("yes\n");
	else printf("no\n");	
}
void Check_network(SetType S,int n)
{
	int i;
	int count=0;
	for(i=0;i<n;i++)
	{
		if(S[i]<0)count++;
	}
	if(count==1)
		printf("The network is connected.\n");
	else
		printf("There are %d components.\n",count);
}
SetName Find(SetType S,ElementType X)
{
	if(S[X]<0)
		return X;
	else
		return S[X]=Find(S,S[X]);
}
void Union(SetType S,SetName Root1,SetName Root2)
{
	if(S[Root2]<S[Root1])
	{
		S[Root2]=S[Root2]+S[Root1];
		S[Root1]=Root2;
	}
	else{
		S[Root1]=S[Root1]+S[Root2];
		S[Root2]=Root1;
	}
}
