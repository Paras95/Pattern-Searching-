 #include <bits/stdc++.h> 
using namespace std; 

#define ROW 3 
#define COL 5 
 
bool isvalid(int row, int col, int prevRow, int prevCol) 
{  
	return (row >= 0) && (row < ROW) && 
		(col >= 0) && (col < COL) && 
		!(row== prevRow && col == prevCol); 
} 

int rowNum[] = {-1, -1, -1, 0, 0, 1, 1, 1}; 
int colNum[] = {-1, 0, 1, -1, 1, -1, 0, 1}; 

void DFS(char mat[][COL], int row, int col, int prevRow, int prevCol, char* word, string path, int index, int n) 
{ 
	if (index > n || mat[row][col] != word[index]) 
		return; 
	path += string(1, word[index]) + "(" + to_string(row) 
			+ ", " + to_string(col) + ") "; 
	if (index == n) 
	{ 
		cout << path << endl; 
		return; 
	} 
	for (int k = 0; k < 8; ++k) 
		if (isvalid(row + rowNum[k], col + colNum[k], 
					prevRow, prevCol)) 

			DFS(mat, row + rowNum[k], col + colNum[k], 
				row, col, word, path, index+1, n); 
}  

void findWords(char mat[][COL], char* word, int n) 
{ 
	for (int i = 0; i < ROW; ++i) 
		for (int j = 0; j < COL; ++j)  
			if (mat[i][j] == word[0]) 
				DFS(mat, i, j, -1, -1, word, "", 0, n); 
}  

int main() 
{ 
	char mat[ROW][COL]= { {'B', 'N', 'E', 'Y', 'S'}, 
						{'H', 'E', 'D', 'E', 'S'}, 
						{'S', 'G', 'N', 'D', 'E'} 
						}; 
	char word[] ="DES"; 
	findWords(mat, word, strlen(word) - 1); 
	return 0; 
} 
