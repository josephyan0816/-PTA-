#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

ElementType FindKth( List L, int K );

int main()
{
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if ( X!= ERROR )
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}
List Read(){
int num;
scanf("%d",&num);
if(num==-1)return NULL;
List list=(List)malloc(sizeof(struct LNode));
List last=list;
list->Data=num;
list->Next=NULL;
scanf("%d",&num);
while(num!=-1){
	PtrToLNode node=(PtrToLNode)malloc(sizeof(struct LNode));
	node->Data=num;
	node->Next=NULL;
	last->Next=node;
	last=node;
	scanf("%d",&num);
	
	
}

return list;

}
ElementType FindKth( List L, int K ){
	if(L==NULL)return ERROR;
	
	if(K<=0)return ERROR;
	PtrToLNode node=L;
	int i=1;
	while(node!=NULL&&i<K){
		if(node->Next==NULL)break;
		node=node->Next;
		i++;
		
		
	}
	if(i<K)return ERROR;
	else return node->Data;
}
