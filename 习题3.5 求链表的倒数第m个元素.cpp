#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

ElementType Find( List L, int m );

int main()
{
    List L;
    int m;
    L = Read();
    scanf("%d", &m);
    printf("%d\n", Find(L,m));
    Print(L);
    return 0;
}
List Read()
{
	List p;
	List L=(List)malloc(sizeof(struct Node));
	p=L;
	L->Next=NULL;
	int n;
	scanf("%d",&n);
	int i;
	int num;
	for(i=0;i<n;i++)
	{
		List last=(List)malloc(sizeof(struct Node));
		scanf("%d",&num);
		last->Data=num;
		p->Next=last;
		p=last;
			
	}
	p->Next=NULL;
	return L;
}
ElementType Find( List L, int m )
{
	if(L->Next==NULL)return ERROR;
List p,q;
q=L->Next;
p=L->Next;
 int len=0;
 while(p)
{
	
	len++;
	p=p->Next;
}
if(m>len)return ERROR;
int record;
record=len-m+1;
int i=1;
while(i<record)
{
	q=q->Next;
	i++;
}
return q->Data;
}
void Print( List L )
{
	List pt;
	pt=L->Next;
	while(pt)
	{
	
		printf("%d ",pt->Data);
	pt=pt->Next;
	}
}
