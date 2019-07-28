#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void PrefixTable(char *pattern,int m,int lps[])
{
	int i=1,j=0;
	for(int k=0;k<(m+1);k++)
	{
		lps[k]=0;
	}
	while(i<m)
	{
		if(pattern[i]==pattern[j])
		{
			lps[i]=j+1;
			i++;
			j++;
		}
		else if(j>0)
		{
			j=lps[j-1];
		}
		else
		{
			lps[i++]=0;
		}
	}
}

void kmp(char *text,char* pattern)
{
	int n=strlen(text);
	int m=strlen(pattern);
	int lps[m];
	PrefixTable(pattern,m,lps);
	int i,j;
	i=0,j=-1;
	while(i<n)
	{
		if(pattern[j+1]==text[i])
		{
			i++;
			j++;
		}
		if(j==m)
		{
			printf("Pattern found at index %d",i-j);
			j=lps[j-1];
		}
		else if(i<n && pattern[j+1]!=text[i])
		{
			if(j!=0)
			{
				j=lps[j-1];
			}
			else
			{
				i++;
			}
		}
	}
}

int main()
{
	int n,m,i;
	scanf("%d %d",&n,&m);
	char text[n],pattern[m];
	printf("Enter the text:\n");
	scanf("%s",text);
	printf("Enter the pattern:\n");
	scanf("%s",pattern);
	kmp(text,pattern);
	return 0;
}
