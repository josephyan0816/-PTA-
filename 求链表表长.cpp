#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

int Length( List L );

int main()
{
    List L = Read();
    printf("%d\n", Length(L));
    return 0;
}
List Read(){
	int num;
	scanf("%d",&num);
	if(num==-1){
		return NULL;
	}
	List list=(List)malloc(sizeof(struct LNode));
	List last=list;
	list->Data=num;
	list->Next=NULL;
	scanf("%d",&num);
	while(num!=-1){
		PtrToLNode node=(List)malloc(sizeof(struct LNode));
		node->Data=num;
		node->Next=NULL;
		last->Next=node;
		last=node;
		scanf("%d",&num);		
	}
	return list;
}

int Length( List L ){
	int len=0;
	while(L){
		L=L->Next;
		len++;
	}
	return len;
	
	
}
