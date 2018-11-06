#include<stdio.h>
#include<stdlib.h>
struct PolyNode{
	int coef;
	int expon;
	struct PolyNode *link; 
	
}; 
typedef struct PolyNode *Polynomial;
Polynomial Read();
void Attach(int c,int e,Polynomial *pRear);
Polynomial PolyAdd(Polynomial P1,Polynomial P2);
void PrintPoly(Polynomial PP);
int main(){
Polynomial P1,P2,P3;
P1=Read();
P2=Read();
P3=PolyAdd(P1,P2); 
PrintPoly(P3);	
	
}
Polynomial Read(){
	int n;
	int c,e;
	Polynomial P,Rear,temp;
	scanf("%d",&n);
	P=(Polynomial)malloc(sizeof(struct PolyNode));
	P->link=NULL;
	Rear=P;
	while(n--){
		scanf("%d%d",&c,&e);
		if(c!=0){
			Attach(c,e,&Rear);
		}
	}
	temp=P;
	P=P->link;
	free(temp);
	return P;
}
void Attach(int c,int e,Polynomial *pRear){
	Polynomial P;
	P=(Polynomial)malloc(sizeof(struct PolyNode));
	P->coef=c;
	P->expon=e;
	P->link=NULL;
	(*pRear)->link=P;//这里用指针的指针的时候dev是不会提示的
	*pRear=P;
	
}
Polynomial PolyAdd(Polynomial P1,Polynomial P2){
	Polynomial rear,front,temp;
	int sum;
	rear=(Polynomial)malloc(sizeof(struct PolyNode));
	front=rear;
	while(P1&&P2){
	
		if(P1->expon>P2->expon){
			Attach(P1->coef,P1->expon,&rear);
			P1=P1->link;
		
		}						//何老师原来的视频中有compare，但是这个在c的库函数中并没有，
								//实现的方法可以自己写了一个compare函数或者像我这样直接比较
																
		else if(P1->expon<P2->expon){
			Attach(P2->coef,P2->expon,&rear);
			P2=P2->link;
		
		}
		else{
			sum=P1->coef+P2->coef;
			if(sum)Attach(sum,P1->expon,&rear);
			P1=P1->link;
			P2=P2->link;
		
		}
		
	
	
		}	
	for(;P1;P1=P1->link)Attach(P1->coef,P1->expon,&rear);
	
	for(;P2;P2=P2->link)Attach(P2->coef,P2->expon,&rear);
	rear->link=NULL;
	temp=front;
	front=front->link;
	free(temp);
	return front;
}
void PrintPoly(Polynomial P){
	
	
	int flag=0;
	while(!P){
		printf("0 0");
		return ;
	}
	while(P){
		if(!flag)flag=1;
		else printf(" ");
		printf("%d %d",P->coef,P->expon);
		P=P->link;
	}
	printf("\n");
}
