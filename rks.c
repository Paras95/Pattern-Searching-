#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define d 256

void search(char *text,char *pattern,int q)
{
	int n=strlen(text);
	int m=strlen(pattern);
	int t=0,i,j;
	int p=0;
	int h=1;
	for(i=0;i<m-1;i++)
	{
		h=(h*d)%q;
	}
	for(j=0;j<m;j++)
	{
		p=(p*d+pattern[j])%q;
		t=(t*d+text[j])%q;
	}
	for(int i=0;i<=n-m;i++)
	{
		if(p==t)
		{
			for(j=0;j<m;j++)
			{
				if(text[i+j]!=pattern[j])
				{
					break;
				}
			}
			if(j==m)
			{
				printf("pattern found:\n");
			}
			else
			{
				printf("I am again fail because of Bangali:\n");
			}
		}
		if(i<n-m)
		{
			t=(d*(t-text[i]*h)+text[i+m])%q;
			if(t<0)
			{
				t=t+q;
			}
		}
	}
	return;
}
int main()
{
	int n,m;
	scanf("%d %d",&m,&n);
	char text[n],pattern[m];
	scanf("%s",text);
	scanf("%s",pattern);
	int q;
	printf("Enter the prime number:\n");
	scanf("%d",&q);
	search(text,pattern,q);
	return 0;
}
