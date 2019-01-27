#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node *PtrToNode;
typedef PtrToNode LinkList;
typedef PtrToNode Position;



struct Node{
	int data;
	Position next;
};


 void printLastKth(LinkList L,int k);
LinkList create();
void destory(LinkList L);
int main()
{
	int k;
	LinkList L;
	scanf("%d",&k);
	L=create();
printLastKth(L,k);

	destory(L);
}
LinkList create()
{
	LinkList head,p,r;
	
	int x;
	head=(struct Node*)malloc(sizeof(struct Node));
	r=head;
	scanf("%d",&x);
	while(x!=-1)
	{
		p=(struct Node*)malloc(sizeof(struct Node));
		p->data=x;
		r->next=p;
		r=p;
		scanf("%d",&x);		
	}
	r->next=NULL;
	return head;
	
	
	
 } 
 void printLastKth(LinkList L,int k)
 {
 	Position p1,p2;
 	int i;
 	p1=L;
 	p2=L;
 	for(i=0;i<k;i++)
 	{
 		p2=p2->next;
 		if(p2==NULL)break;
	 }
	 if(p2==NULL)printf("NULL");
	 else{
	 	while(p2!=NULL)
	 	{
	 		p2=p2->next;
	 		p1=p1->next;
		 }
		 printf("%d",p1->data);
	 }
 }
 void destory(LinkList L)
 {
 	LinkList p,q;
 	p=L->next;
 	while(p)
 	{
 		q=p->next;
 		free(p);
 		p=q;
	 }
	 L=NULL;
 }
