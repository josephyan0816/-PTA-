#include<stdio.h> 
#include<string.h>

#include<stdlib.h>

void swap(int* a,int* b);
void simpleSelection(int a[],int n);
int main()
{
	int n;
	int i;
	scanf("%d",&n);
	int a[n];
	int flag=1;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	simpleSelection(a,n);
	for(int i=0;i<n;i++)
	{
		if(flag)
		{
			flag=0;
			printf("%d",a[i]);
		}
		else printf(" %d",a[i]);
	}
}
void simpleSelection(int a[],int n)
{
	int i,j;
	int min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
			if(a[j]<a[min])
				min=j;
		swap(&a[i],&a[min]);		
	}
}
void swap(int* a,int* b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
