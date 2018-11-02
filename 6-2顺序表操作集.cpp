#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h> 
#define MAXSIZE 5
#define ERROR -1
//typedef enum {false, true} ;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        if ( Insert(L, X, 0)==false )
            printf(" Insertion Error: %d is not in.\n", X);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else
            printf("%d is at position %d.\n", X, P);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &P);
        if ( Delete(L, P)==false )
            printf(" Deletion Error.\n");
        if ( Insert(L, 0, P)==false )
            printf(" Insertion Error: 0 is not in.\n");
    }
    return 0;
}
List MakeEmpty(){
	List p;
	p=(List)malloc(sizeof(struct LNode));
	p->Last=-1;
	return p;
}

Position Find( List L, ElementType X ){
	/*	Position i=0;
	while(i<=L->Last&&L->Data[i]!=X)
		i++;
		if(i>L->Last)return ERROR;
		else return i;
	*/
	int i;
	for(i=0;i<=L->Last;i++){
		if(L->Data[i]==X){
		return i;
		}
	}
	return ERROR;
}
bool Insert( List L, ElementType X, Position P ){
/*	Position j;
	if(L->Last==MAXSIZE-1){
		printf("FULL");
		return false;
	}
	if(P<0||P>L->Last+1){
		printf("ILLEGAL POSITION");
		return false;
	}
	for(j=L->Last;j>=P-1;j--){
		L->Data[j+1]=L->Data[j];
		L->Data[P-1]=X;
		L->Last++;
		return true;
	}
*/
  if(L->Last==MAXSIZE-1){//容量慢
        printf("FULL");
        return false;
    }
    if(P<0||P>L->Last+1){//只能查到已有数字的位置或最后一个的下一个
        printf("ILLEGAL POSITION");
        return false;
    }
    int i;
    for(i = L->Last+1; i > P; i--){
        L->Data[i] = L->Data[i-1];//向右平移
    }
    L->Data[i] = X;//插入
    L->Last++;//个数增加
    return true;
	
}
bool Delete( List L, Position P ){
	int	 i;
	if(P<0||P>L->Last)
	{
		printf("POSITION %d EMPTY",P);
		return false;
	}
	for(i=P;i<L->Last;i++)
		L->Data[i]=L->Data[i+1];
		
		
	
	L->Last--;
	return true;
}
