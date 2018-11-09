#include <stdio.h>
#include <stdlib.h>
#include<string.h> 
#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;
//typedef enum { false, true } bool;
typedef int Position;
struct SNode {
    ElementType *Data;
    Position Top1, Top2;
    int MaxSize;
};
typedef struct SNode *Stack;

Stack CreateStack( int MaxSize );
bool Push( Stack S, ElementType X, int Tag );
ElementType Pop( Stack S, int Tag );

Operation GetOp();  /* details omitted */
void PrintStack( Stack S, int Tag ); /* details omitted */

int main()
{
    int N, Tag, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while ( !done ) {
        switch( GetOp() ) {
        case push: 
            scanf("%d %d", &Tag, &X);
            if (!Push(S, X, Tag)) printf("Stack %d is Full!\n", Tag);
            break;
        case pop:
            scanf("%d", &Tag);
            X = Pop(S, Tag);
            if ( X==ERROR ) printf("Stack %d is Empty!\n", Tag);
            break;
        case end:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
    }
    return 0;
}
Stack CreateStack( int MaxSize ){
	Stack S=(Stack)malloc(sizeof(struct SNode));
	S->Data=(ElementType*)malloc(MaxSize*sizeof(ElementType));
	S->Top1=-1;
	S->Top2=MaxSize;
	S->MaxSize=MaxSize;
	return S;
	
} 
bool Push( Stack S, ElementType X, int Tag ){
	if(S==NULL){
		return false;
	}
	if(S->Top2-S->Top1==1)
	{
	
		printf("Stack Full");
		return false;
	}
	else
	{
		if(Tag==1)
		{
			S->Data[++(S->Top1)]=X;
		}
		else
		{
			S->Data[--(S->Top2)]=X;
		}
		return true;
	}
	
}
ElementType Pop( Stack S, int Tag )
{
	if(S==NULL){
		return ERROR;
	}
	if(Tag==1)
	{
		if(S->Top1==-1)
		{
			printf("Stack %d Empty\n",Tag);
			return ERROR;
		}
		else return S->Data[(S->Top1)--];
	}
	else
	{
		if(S->Top2==S->MaxSize){
			printf("Stack %d Empty\n",Tag);
			return ERROR;
		}
		else return S->Data[(S->Top2)++];
	}
}
Operation GetOp(){
	char a[5];
	scanf("%s",a);
	if(strcmp(a,"Push")==0)return push;
	if(strcmp(a,"Pop")==0)return pop;
	if(strcmp(a,"End")==0)return end;
}
void PrintStack( Stack S, int Tag )
{
	if(Tag==1)
	{
		printf("Pop from Stack 1: ");
		while((S->Top1)!=-1)
		{
			printf("%d ",S->Data[(S->Top1)--]);
		}
		printf("\n");
	}
	else
	{
		printf("Pop from Stack 2: ");
		while((S->Top2)!=S->MaxSize)
		{
			printf("%d ",S->Data[(S->Top2)++]);
		}
		printf("\n");
	}
	
}
