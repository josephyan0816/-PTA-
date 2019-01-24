#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void InsertionSort(int a[],int n);
int main() 
{
	int i;
	int flag=1;
	int n;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	InsertionSort(a,n);
	for(int i=0;i<n;i++)
	{
		if(flag)
		{
			printf("%d",a[i]);
			flag=0;
		}
		else{
			printf(" %d",a[i]);
		}
	 } 
	
}
void InsertionSort(int a[],int n)
{
	int p,i;
	int temp;
	for(p=1;p<n;p++)
	{
		temp=a[p];
		for(i=p;i>0&&a[i-1]>temp;i--)
			a[i]=a[i-1];
		a[i]=temp;	
	}
	
	
}
