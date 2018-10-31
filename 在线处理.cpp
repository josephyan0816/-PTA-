#include<stdio.h>
int MaxSubseqSum4(int List[],int N){
	
	int i;
	int ThisSum,MaxSum;
	ThisSum=MaxSum=0;
	for(i=0;i<N;i++){
		ThisSum+=List[i];
		if(ThisSum>MaxSum)
			MaxSum=ThisSum;
		else if(ThisSum<0)
		ThisSum=0;	
	}
	return MaxSum;
} 
int main(){
	int a[8]={-1,3,-2,4,-6,1,6,-1};
	int k;
	k=MaxSubseqSum4(a,8);
	printf("%d",k);
}
