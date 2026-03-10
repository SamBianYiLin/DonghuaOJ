#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	int n;
	while (scanf("%d", &n) > 0) {
		vector<vector<int>> matrix(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &matrix[i][j]);
			}
		}
		vector<vector<int>> matrix_reverse(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix_reverse[i][j] = matrix[j][i];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (j == n - 1) {
					printf("%d", matrix_reverse[i][j]);
				}
				else {
					printf("%d ", matrix_reverse[i][j]);
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}