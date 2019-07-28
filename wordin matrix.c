#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROW 3
#defien COL 5

int rowNum[]={-1,-1,-1,0,0,1,1,1};
int colNum[]={-1,0,1,-1,1,-1,0,1};

bool isValid(int row,int col,int PreRow,int PreCol)
{
	return((row>=0) && (row<ROW) && (col>=0) && (col<COL) && !(row==PreRow && col==PreCol));
}
void DFS(char mat[][COL],int row,int col,int preRow,int preCol,char *word,string path,int index,int n)
{
	
}
void findWords(char mat[][COL],char *word,int n)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if[(mat[i][j]==word[0])
			{
				DFS(mat,i,j,-1,-1,word,"",0,n);
			}
		}
	}
	return;
}
}
int main()
{
	int n,i;
	char mat[row][col]={{'B','N','E','Y','S'},
		                 {'H','E','D','E','S'},
		                  {'S','G','N','D','E'}
		               };
	char word[]="DES";
	findsWords(mat,word,strlen(word)-1);
	return 0;	               
}
