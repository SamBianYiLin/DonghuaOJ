#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	int n;
	while (scanf("%d", &n) > 0) {
		vector<vector<int>> matrix(n, vector<int>(n, 0));
		/*int line = 100 * n;
		int currentNum = 2;
		int currentColumn = n / 2;
		int column = currentColumn;
		for (int i = 0; i < n; i++)
		{
			for (int j = currentColumn; j < currentColumn + n ; j++)
			{
				if (i == 0 && j == n / 2) {
					matrix[i][j] = 1;
				}
				else {
					matrix[(line - 1) % n][(column + 1) % n] = currentNum;
					line--; column++; currentNum++; 
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%d ", matrix[i][j]);
			}
			printf("\n");
		}
			printf("\n");*/
		int column = n / 2;
		int row = 0;
		int curNum = 1;
		matrix[row][column] = 1;
		for (curNum = 2; curNum <= n * n; curNum++) {
			int newRow = (row - 1 + n) % n;
			int newColumn = (column + 1) % n;
			if (matrix[newRow][newColumn] != 0) {
				newRow = (row + 1) % n;
				newColumn = column;
			}
			row = newRow;
			column = newColumn;
			matrix[row][column] = curNum;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j != n - 1) {
					printf("%d ", matrix[i][j]);
				}
				else {
					printf("%d", matrix[i][j]);
				}
			}
			// printf("\n");
		}
	}
	return 0;
}