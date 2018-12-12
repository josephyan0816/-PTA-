#include<stdio.h>
#include<stdlib.h>
typedef struct LNode *PtrToLNode;
typedef int ElementType;

struct LNode{
	ElementType Data;
	PtrToLNode Next;	
};
typedef PtrToLNode List;
List Read();
List mergeList(List L1,List L2);
void Print(List L);
int main()
{
	List L1=Read();
	List L2=Read();
	List L3=mergeList(L1,L2);
	Print(L3);
	
}
List Read()
{
	List L,head;
	L=(List)malloc(sizeof(struct LNode));
	head=L;
	L->Next=NULL;
	
	int num;
	scanf("%d",&num);
	while(num!=-1)
	{
		List last=(List)malloc(sizeof(struct LNode));
		last->Data=num;
		last->Next=NULL;
		L->Next=last;
		L=last;
		scanf("%d",&num);
	}
	L->Next=NULL;
	return head;
}
List mergeList(List L1,List L2)
{
	List L,p,pt,q;
	L=(List)malloc(sizeof(struct LNode));
	L->Next=NULL;
	pt=L;
	p=L1->Next;
	q=L2->Next;
	while(p&&q)
	{
		if(p->Data<=q->Data)
		{
			pt->Next=p;
			pt=p;
			p=p->Next;
		}
		else{
			pt->Next=q;
			pt=q;
			q=q->Next;
		}
		
	}
	pt->Next=p?p:q;
	return L;
}
void Print(List L)
{
	if(L->Next==NULL)
	{
		printf("NULL");
	}
	
	List p;
	p=L->Next;
	while(p)
	{
		if(p->Next!=NULL)printf("%d ",p->Data);
		else printf("%d",p->Data);
		p=p->Next; 
	}
	
}
