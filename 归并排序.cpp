#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n;
typedef int ElementType;


void Merge(ElementType A[],ElementType TmpA[],int L,int R,int RightEnd)
{
	int LeftEnd,NumElements,Tmp;
	int i;
	
	LeftEnd=R-1;
	Tmp=L;
	NumElements=RightEnd-L+1;
	while(L<=LeftEnd&&R<=RightEnd)	
	{
		if(A[L]<=A[R])	
			TmpA[Tmp++]=A[L++];
		else
			TmpA[Tmp++]=A[R++];
	}
	while(L<=LeftEnd)
		TmpA[Tmp++]=A[L++];
	while(R<RightEnd)
	{
		TmpA[Tmp++]=A[R++];
	}
	for(i=0;i<NumElements;i++,RightEnd--)
	A[RightEnd]=TmpA[RightEnd];
}
void Msort(ElementType A[],ElementType TmpA[],int L,int RightEnd)
{
	int center;
	if(L<RightEnd)
	{
		center=(L+RightEnd)/2;
		Msort(A,TmpA,L,center);
		Msort(A,TmpA,center+1,RightEnd);
		Merge(A,TmpA,L,center+1,RightEnd);
	}
}
void MergeSort(ElementType A[],int n)
{
	ElementType *TmpA;
	TmpA=(ElementType *)malloc(sizeof(ElementType)*n);
	if(TmpA!=NULL)
	{
		Msort(A,TmpA,0,n-1);
		free(TmpA);
	}
	else printf("¿Õ¼ä²»×ã");
}

int main()
{
	
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	MergeSort(a,n); 
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
