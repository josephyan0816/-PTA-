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
List Read(){
	int n;
	scanf("%d",&n);
	List phead=(List)malloc(sizeof(struct Node));//这里的头结点为空 
	List p=phead;
	p->Next=NULL;
	int data;
	while(n--){
		scanf("%d",&data);
		List pNode=(List)malloc(sizeof(struct Node));
		pNode->Data=data;
		pNode->Next=NULL;
		p->Next=pNode;
		p=pNode;
	}
	
	return phead;

} 
void Print( List L ){
	List p=L->Next;		//这里如果直接用P=L的话虽然没有报错，但是结果却不对，L这里有头结点 
	if(p==NULL){
		printf("NULL");
	}
	while(p!=NULL){
		printf("%d ",p->Data);
		p=p->Next;
		
	}
	printf("\n");
	
}
List Merge( List L1, List L2 ){
	if(L1->Next==NULL)
	{
		List temp,L;
		L=(List)malloc(sizeof(struct Node));
		temp=L2;					//L1为空表，将L2的数据写进L 
		L2=L2->Next;
		L->Next=L2;
		while(L2)
		{
			temp->Next=L2->Next;
			L2=L2->Next; 
		}
		return L;
	}
	else if(L2->Next==NULL)
	{								//L2为空表，将L1的数据写入L 
		List temp,L;						 
		L=(List)malloc(sizeof(struct Node));
		temp=L1;
		L1=L1->Next;
		L->Next=L1;
		while(L1)
		{
			temp->Next=L1->Next;
			L1=L1->Next;
		}
		return L;
		
	}
	else		//2表都不为空时 
	{
		List LL=(List)malloc(sizeof(struct Node));
		List LLL=LL;
		List temp1,temp2;
		temp1=L1;
		temp2=L2;
		L1=L1->Next;
		L2=L2->Next;
		while(L1&&L2)
		{
			if(L1->Data<L2->Data)
			{
				LL->Next=L1;
				LL=LL->Next;
				temp1->Next=L1->Next;
				L1=L1->Next;
			}
			else
			{
				LL->Next=L2;
				LL=LL->Next;
				temp2->Next=L2->Next;
				L2=L2->Next;
			}
			
		}
		while(L1)
		{
			LL->Next=L1;
			LL=LL->Next;
			temp1->Next=L1->Next;
			L1=L1->Next;
		}
		while(L2)
		{
			LL->Next=L2;
			LL=LL->Next;
			temp2->Next=L2->Next;
			L2=L2->Next;
			
			
		}
		return LLL;
	}
	
}
