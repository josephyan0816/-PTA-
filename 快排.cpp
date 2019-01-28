#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<stdio.h>

int partition(int a[],int left,int right)
{
    int low=left;
    int high=right;
    int temp=a[low];
    while(low<high)
    {
        while(low<high&& a[high]>=temp)
            high--;
            if(low<high)
                a[low]=a[high];
        while(low<high && a[low]<=temp)
            low++;
            if(low<high)
                a[high]=a[low];
    }
    a[low]=temp;
    return low;
}
void quickSort(int a[],int left,int right)
{
    int dp;
    if(left<right)
    {
        dp=partition(a,left,right);
        quickSort(a,left,dp-1);
        quickSort(a,dp+1,right);
    }
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
	quickSort(a,0,n-1);

	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	
}

