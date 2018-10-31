#include<stdio.h>
int MaxSubseSum(int List[],int N);
int main(){
	int a[100000];
	int k;
	scanf("%d",&k);
	int i;
	for(i=0;i<k;i++){
		scanf("%d",&a[i]);
	}
	int n;
	n=MaxSubseSum(a,k);
	printf("%d",n);
} 
int MaxSubseSum(int List[],int N){
	
	
	int i;
	int ThisSum,MaxSum;
	ThisSum=MaxSum=0;
	for(i=0;i<N;i++){
		ThisSum=ThisSum+List[i];
		if(ThisSum>MaxSum)
		MaxSum=ThisSum;
		else if(ThisSum<0)
		ThisSum=0;
	}
	return MaxSum;
}
