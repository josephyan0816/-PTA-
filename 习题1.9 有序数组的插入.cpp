#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList( List L ); /* 裁判实现，细节不表 */
bool Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;

    L = ReadInput();
    scanf("%d", &X);
    if ( Insert( L, X ) == false )
        printf("Insertion failed.\n");
    PrintList( L );

    return 0;
}
List ReadInput()
{
	List a;
	int i;
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a->Data[i]);
	}
	a->Last=n-1;
	
	return a;
}
bool Insert( List L, ElementType X )
{
	
	int i;
	int k; 
	int findex=0;
	if(L->Last>=MAXSIZE)return false;
	for(i=0;i<=L->Last;i++)
	{
		if(L->Data[i]>X)
		{
			findex=i+1;
			//break;
		}
		else if(L->Data[i]==X)return false;
	}
	if(findex>=MAXSIZE)return false;
	if(findex<=L->Last)
	{
		for(k=L->Last;k>=findex;k--)
		{
			L->Data[k+1]=L->Data[k];
		}
	}
	L->Data[findex]=X;
	L->Last++;
	
	return true;
	
	
	
}
void PrintList( List L )
{
	int len;
	int i;
	len=L->Last;
	for(i=0;i<=len;i++)
	{
		printf("%d ",L->Data[i]);
	}
	printf("\n");
	printf("Last = %d",L->Last);
}
