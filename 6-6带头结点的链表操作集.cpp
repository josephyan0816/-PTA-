#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
//typedef enum{false, true} bool;	//这里我一开始始终报错，因为在dev中bool已经定义过了
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

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
    bool flag;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        flag = Insert(L, X, L->Next);
        if ( flag==false ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            flag = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( flag==false )
                printf("Wrong Answer.\n");
        }
    }
    flag = Insert(L, X, NULL);
    if ( flag==false ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    flag = Insert(L, X, P);
    if ( flag==true ) printf("Wrong Answer\n");
    flag = Delete(L, P);
    if ( flag==true ) printf("Wrong Answer\n");
    for ( P=L->Next; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}
List MakeEmpty(){
	List L;
	L=(List)malloc(sizeof(struct LNode));
	L->Next=NULL;
	
	return L;
}
Position Find( List L, ElementType X )
{
	L=L->Next;
	while(L!=NULL)
	{
		if(L->Data==X)
		{
			return L;
		}
		L=L->Next;
	}
	return ERROR;
}
bool Insert( List L, ElementType X, Position P )			//这里书上传递的是int，但实际上这里应该传指针
{									//不能直接像书上那样直接写，我一开始死活不懂，书上的代码是伪的，int代表的是位置							
	Position q=(Position)malloc(sizeof(struct LNode));
	q->Data=X;
	q->Next=P;
	while(L!=NULL)
		{
			if(L->Next==P)
			{
				L->Next=q;
				return true;
			}
			L=L->Next;
		}
		printf("Wrong Position for Insertion\n");
		return false;
}
bool Delete( List L, Position P )
{
	while(L!=NULL)
	{
		if(L->Next==P)
		{
			L->Next=P->Next;
			return true; 
		}
		L=L->Next;
	}
	printf("Wrong Position for Deletion\n");
	return false;
}
