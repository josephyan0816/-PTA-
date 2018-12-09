#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

List Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    L = Read();
    scanf("%d", &X);
    L = Insert(L, X);
    Print(L);
    return 0;
}
List Read()
{
	int num;
	int n;
	List L=(List)malloc(sizeof(struct Node));
	List head;
	L->Next=NULL;
	head=L;
	scanf("%d",&n);
	if(n==0)return head;
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		List last=(List)malloc(sizeof(struct Node));
		last->Data=num;
		L->Next=last;
		L=last;
	}
	L->Next=NULL;
	return head;
}
List Insert( List L, ElementType X )
{
	List t=(List)malloc(sizeof(struct Node));
	t->Data=X;
	t->Next=NULL;
	List head=L;
	while(L->Next&&L->Next->Data<X)
	{
		L=L->Next;		
	}
	t->Next=L->Next;
	L->Next=t;
return head	;
}
void Print( List L )
{
	List p;
	p=L;
	while(p->Next)
	{
		p=p->Next;
		printf("%d ",p->Data);
		
	}
	
	
}
