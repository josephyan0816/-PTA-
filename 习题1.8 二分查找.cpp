#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}
List ReadInput()
{
	int n;
	scanf("%d",&n);
	int i;
	List a;
	
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a->Data[i]);
		
	}
	a->Last=n;
	return a;
}
Position BinarySearch( List L, ElementType X )
{
	Position left,right,mid;
	
	left=1;
right=L->Last;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(L->Data[mid]==X)return mid;
		else if(L->Data[mid]<X)left=mid+1;
		else if(L->Data[mid]>X)right=mid-1;
	}
	return NotFound;
}
