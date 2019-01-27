#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef int Position;
#define NotFound -1

Position KMP(char *string,char *pattern);
void BuildMatch(char *pattern,int *match);
int main()
{
	char str[]="This is a simple example";
	char pattern[]="simple";
	Position p=KMP(str,pattern);
	if(p==NotFound)printf("Not Found.\n");
	else printf("%s\n",str+p);
	
 } 
Position KMP(char *string,char *pattern)
{
	int n=strlen(string);
	int m=strlen(pattern);
	int s,p,*match;
	match=(int*)malloc(sizeof(int)*m);
	BuildMatch(pattern,match);
	s=p=0;
	while(s<n&&p<m)
	{
		if(string[s]==pattern[p])
		{
			s++;
			p++;
		}
		else if(p>0) p=match[p-1]+1;
		else s++;
	}
	return (p==m)?(s-m):NotFound;
}
void BuildMatch(char *pattern,int *match)
{
	int i,j;
	int m=strlen(pattern);
	match[0]=-1;
	for(j=1;j<m;j++)
	{
		i=match[j-1];
		while((i>=0)&&(pattern[i+1]!=pattern[j]))
		{
			i=match[i];
		}
		if(pattern[i+1]==pattern[j])
			match[j]=i+1;
		else match[j]=-1;	
	}
}
