#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; 
};

List ReadInput(); 
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
List ReadInput(){
	int n;
	scanf("%d",&n);
	List list=(List)malloc(sizeof(struct LNode));
	list->Last=n;
	for(int i=1;i<=n;i++)
		scanf("%d",&list->Data[i]);
	return list;
	
}
Position BinarySearch( List L, ElementType X ){
			Position right,left,mid;
			left=1;right=L->Last;
			while(left<=right){
				mid=(left+right)/2;
				if(L->Data[mid]<X){
						left=mid+1;
				}
				else if(L->Data[mid]>X){
					right=mid-1;
				}
				else return mid;
				
			}

return NotFound ;
}
