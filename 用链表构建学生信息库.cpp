#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node * PtrToNode;
struct Node{
	int num;
	int score;
	char name[20];
	PtrToNode next;
};
typedef PtrToNode List;
List create();
List insert(List head,List L);
List deletelist(List head,int num);
void print(List L);

int main()
{
	List head,p;
	int choice,num,score;
	char name[20];
	int size=sizeof(struct Node);
	do{
		printf("1:Create 2:Insert 3:Delete 4:Print 0:Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				head=create();
				break;
			case 2:
				printf("Input num,name and score:\n");
				scanf("%d%s%d",&num,name,&score);
				p=(List)malloc(sizeof(struct Node));
				p->num=num;
				strcpy(p->name,name);
				p->score=score;
				head=insert(head,p);
				break;
			case 3:
				printf("Input num:\n");
				scanf("%d",&num);
				head=deletelist(head,num);
				break;
			case 4:
				print(head);
				break;
			case 0:
				break;				
		}
	}while(choice!=0);
	
	
	
 } 
 List create()
 {
 	List head,p;
 	int num;
 	int score;
 	char name[20];
 	int size=sizeof(struct Node);
 	head=NULL;
 	printf("Input num,name and score:\n");
 	scanf("%d%s%d",&num,name,&score);
 	while(num!=0)
 	{
 		p=(List)malloc(sizeof(struct Node));
 		p->num=num;
 		strcpy(p->name,name);
 		p->score=score;
 		head=insert(head,p);
 		scanf("%d%s%d",&num,name,&score);
 		
 		
	 }
	 return head;
 }
 List insert(List head,List stu)
 {
 	List ptr1,ptr2,ptr;
 	ptr2=head;
 	ptr=stu;
 	if(head==NULL)
 	{
 		head=ptr;
 		head->next=NULL;
	 }
	 else
	 {
	 	while((ptr->num>ptr2->num)&&(ptr2->next!=NULL))
	 	{
	 		ptr1=ptr2;
	 		ptr2=ptr2->next;
		 }
	 	if(ptr->num<=ptr2->num)
	 	{
	 		if(head==ptr2)head=ptr;
	 		else ptr1->next=ptr;//这里有3个指针所以不存在改变顺序就覆盖节点的情况，我一开始在这里困惑了半天 
	 		ptr->next=ptr;
	 		ptr->next=ptr2;
	 	
		 }
	 	else{
	 		ptr2->next=ptr;
	 		ptr->next=NULL;
		 }
	 	
	 }
	 return head;
 }
 List deletelist(List head,int num)
 {
 	List ptr1,ptr2;
 	while(head!=NULL&&head->num==num)
 	{
 		ptr2=head;
 		head=head->next;
 		free(ptr2);
	 }
 	if(head==NULL)
 	return NULL;
 	ptr1=head;
 	ptr2=head->next;
 	while(ptr2!=NULL)
 	{
 		if(ptr2->num==num)
 		{
 			ptr1->next=ptr2->next;
 			free(ptr2);
		 }
		 else
		 	ptr1=ptr2;
		 	ptr2=ptr1->next;
	 }
 	
 	return head;
  }
 void print(List head)
 {
 	List ptr;
 	if(head==NULL)
 	{
 		printf("\nNO records\n");
 		
	 }
	 printf("\nThe students' records are :\n");
	 printf("Num\tName\tScore\n");
	 for(ptr=head;ptr!=NULL;ptr=ptr->next)
	 {
	 	printf("%d\t%s\t%d\n",ptr->num,ptr->name,ptr->score);
	 }
   }  
