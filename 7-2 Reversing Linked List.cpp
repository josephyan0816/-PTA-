#include<stdio.h>
#include<stdlib.h>
typedef struct Node *LinkList;
struct Node{
	int data;
	int ad;
	int nad;
	LinkList next;
};


int main()
{
	LinkList L1,p1,q1;
	L1=(LinkList)malloc(sizeof(struct Node));
	L1->next=NULL;
	int firstad;
	int K,N;
	int i;
	scanf("%d%d%d",&firstad,&N,&K);
	p1=L1;
	for(i=0;i<N;i++)
	{
		q1=(LinkList)malloc(sizeof(struct Node));
		scanf("%d%d%d",&q1->ad,&q1->data,&q1->nad);
		p1->next=q1;
		p1=q1;
	}
	p1->next=NULL;
	
	LinkList L2,p2;
	L2=(LinkList)malloc(sizeof(struct Node));
	L2->next=NULL;
	int findad=firstad;
	int cnt=0;
	p2=L2;
	while(findad!=-1)
	{
		q1=L1;
		while(q1->next)
		{
			if(q1->next->ad==findad)
			{
				p2->next=q1->next;
				q1->next=q1->next->next;
				p2=p2->next;
				cnt++;
				findad=p2->nad;
			}
			else{
				q1=q1->next;
			}
		}
	}
	p2->next=NULL;
	
	LinkList L3,p3,q3,tail;
	L3=(LinkList)malloc(sizeof(struct Node));
	L3->next=NULL;
	int n=cnt;
	int k=K;
	p3=L3;
	p2=L2;
	while(n>=k)
	{
		n=n-k;
		for(int i=0;i<k	;i++)
		{
			p3->next=p2->next;
			p2->next=p2->next->next;
			if(i==0)
				tail=p3->next;
			else
				p3->next->next=q3;
				q3=p3->next;
		}
		p3=tail;
	}
	p3->next=L2->next;
	p3=L3->next;
	while(p3->next)
	{
		printf("%05d %d %05d\n",p3->ad,p3->data,p3->next->ad);
		p3=p3->next;
	}
	
	printf("%05d %d -1\n",p3->ad,p3->data);
 } 
