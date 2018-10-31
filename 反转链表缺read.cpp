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

List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}
/*List Read(){
  int len;
  scanf("%d",&len);
  int i=1;
  List list=(List)malloc(sizeof(struct Node));
  
  
  for(i=1;i<=len;i++){
  	scanf("%d",&list->Data);
	list=list->Next;	 
  }
  
  }
  
void Print( List L ){
	PtrToNode last=L;
	while(last!=NULL){
		printf("%d",last->Data);
		last=last->Next;
	}
}*/
// read部分和print部分我写的是错的，但是这个反转算法我是根据书上改的，在PTA上能跑 

List Reverse( List L ){
	List oldhead,newhead,temp;
	oldhead=L;
	newhead=NULL;
	while(L){
		temp=oldhead->Next;
		oldhead->Next=newhead;
		newhead=oldhead;
		oldhead=temp;
	}
	L=newhead;
	return L;
}
