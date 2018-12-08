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
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}
List Read()
{
	int n;
	int i;
	int num;
	List p;
	List L=(List)malloc(sizeof(struct Node));
	p=L;
	L->Next=NULL;
	 scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		
		List Last=(List)malloc(sizeof(struct Node));
		scanf("%d",&num);
		Last->Data=num;
		p->Next=Last;
		p=Last;
	}
	p->Next=NULL;
	return L;
	
 } 
 List Merge( List L1, List L2 )
 {
 	List pt,p,q;
 	List Lj=(List)malloc(sizeof(struct Node));
 	Lj->Next=NULL;
	  pt=Lj;
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
	  	else
	  	{
	  		pt->Next=q;
	  		pt=q;
	  		q=q->Next;
		  }
	  	
	  }
	  pt->Next=p?p:q;
	  L1->Next=NULL;
	  L2->Next=NULL;
	  
 	return Lj;
 }
 void Print( List L )
 {
 	if(L->Next==NULL)
 	{
 		printf("NULL\n");
	 }
else{
	 List r=L;
	 r=L->Next;
	 while(r)
	 {
	 	printf("%d ",r->Data);
	 	r=r->Next;

	 }
	 if(r==NULL)printf("\n");
}
 }
