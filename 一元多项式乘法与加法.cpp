#include<stdio.h>
#include<stdlib.h> 
typedef struct PolyNode* Polynomial;
struct PolyNode{
	int coef;
	int expon;
	Polynomial next;
}; 
Polynomial ReadPoly();
Polynomial Add(Polynomial P1,Polynomial P2);
Polynomial Mult(Polynomial P1,Polynomial P2);
void Attach(int c,int e,Polynomial *pRear);
void PrintPoly(Polynomial PP);


int main(){
	Polynomial P1,P2,PP,PS;
	P1=ReadPoly();
	P2=ReadPoly();
	PP=Mult(P1,P2);
	PrintPoly(PP);
	PS=Add(P1,P2);
	PrintPoly(PS);
	
}

void Attach(int c,int e,Polynomial *pRear){
	Polynomial P;
	P=(Polynomial)malloc(sizeof(struct PolyNode));
	P->coef=c;
	P->expon=e;
	P->next=NULL;
	(*pRear)->next=P;
	*pRear=P;
	
	
	
}
Polynomial ReadPoly(){
	int n;
	int c,e;
	Polynomial P,Rear,t;
	
	scanf("%d",&n);
	P=(Polynomial)malloc(sizeof(struct PolyNode));
	P->next=NULL;
	Rear=P;
	while(n--){
		scanf("%d%d",&c,&e);
		if(c!=0)
			Attach(c,e,&Rear);
	}
	t=P;
	P=P->next;
	free(t);
	return P;
}
Polynomial Add(Polynomial P1,Polynomial P2){
	Polynomial t1,t2;
	t1=P1;
	t2=P2;
	Polynomial P,t;
	P=(Polynomial)malloc(sizeof(struct PolyNode));
	P->next=NULL;
	Polynomial Rear;
	Rear=P;
	while(t1&&t2){
		if(t1->expon==t2->expon){
				if(t1->coef+t2->coef){/*我一开始的问题在这个t1的1没有打出来，但是我的dev并未报错，PTA没有打印第2行*/
					Attach(t1->coef+t2->coef,t1->expon,&Rear);
				}
			t1=t1->next;
			t2=t2->next;
			
			
		}
		else if(t1->expon>t2->expon){
			Attach(t1->coef,t1->expon,&Rear);
			t1=t1->next;
		}
		else {
			Attach(t2->coef,t2->expon,&Rear);
			t2=t2->next;
			
		}
		
		

		
	}
	while(t1){
		Attach(t1->coef,t1->expon,&Rear);
		t1=t1->next;
	}
	while(t2){
		Attach(t2->coef,t2->expon,&Rear);
		t2=t2->next; 
	}
	t=P;
	P=P->next;
	free(t);
	return P;
} 

Polynomial Mult(Polynomial P1,Polynomial P2){
	Polynomial P,Rear,t1,t2,t;
	int c,e;
	if(!P1||!P2)return NULL;
	t1=P1;
	t2=P2;
	P=(Polynomial)malloc(sizeof(struct PolyNode));
	Rear=P;
	while(t2){
		Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
		t2=t2->next;
	}
	t1=t1->next;
	while(t1){
		t2=P2;
		Rear=P;
		while(t2){
			e=t1->expon+t2->expon;
			c=t1->coef*t2->coef;
			while(Rear->next&&Rear->next->expon>e){
				Rear=Rear->next;
			} 
			if(Rear->next&&Rear->next->expon==e){
				if(Rear->next->coef+c){
					Rear->next->coef+=c;
				}
				else{
					t=Rear->next;
					Rear->next=t->next;
					free(t);
				}	
			}
			else {
				
				t=(Polynomial)malloc(sizeof(struct PolyNode));
				t->coef=c;
				t->expon=e;
				t->next=Rear->next;
				Rear->next=t;
				
				Rear=Rear->next;
				
			}
			t2=t2->next;
		}
		t1=t1->next;
	}
	t2=P;
	P=P->next;
	free(t2);
	return P;
}
void PrintPoly(Polynomial P){
	int flag=0;
	if(!P){
		printf("0 0\n");
		return ;
	}
	while(P){
		if(!flag)flag=1;
		else printf(" ");
		printf("%d %d",P->coef,P->expon);
		P=P->next;
		}
		printf("\n");
	}
	
/*我感觉这个如果一开始学校的课程跟不上的话太正常了，很多学校C都没讲完，C的核心部分就在后面指针那部分，但是我所在的学校基本没怎么讲过，全班都是抄作
这个的话建议跟翁恺老师的C语言进阶把结构指针部分在好好补一下，我一开始就有一个误区，认为链表，结点，数组，顺序表这些没有区别，真的是太naive，学校讲的太弱智了，
我个人感觉想深入的话先跟着浙大MOOC还得看书，在把题做一遍，对，先抄1,2遍，背一下，再开始理解

*/
