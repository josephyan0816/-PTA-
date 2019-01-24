#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main()
{
	int a[51];
	int n;
	int year;
	int i;
	for(i=0;i<51;i++)
	{
		a[i]=0;
	}
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&year);
		a[year]++;
	}
	for(i=0;i<51;i++)
	{
		if(a[i])
		{
			printf("%d:%d\n",i,a[i]);
		}
	}
	
	
	
}
