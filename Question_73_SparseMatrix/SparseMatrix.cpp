#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	int m, n;	//	m行 n列
	while (scanf("%d%d", &m, &n) > 0) {
		vector<vector<int>> matrix(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &matrix[i][j]);
			}
		}
		vector<vector<int>> res((m - 1) * n + 1, vector<int>(3, 0));
		int curLineNum = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] != 0) {
					res[curLineNum][0] = i + 1;
					res[curLineNum][1] = j + 1;
					res[curLineNum][2] = matrix[i][j];
					curLineNum++;
				}
				else {
					continue;
				}
			}
		}
		for (int i = 0; i < (m - 1) * n + 1; i++)
		{
			if (res[i][0] == 0) {
				continue;
			}
			for (int j = 0; j < 3; j++)
			{
				if (j != 2) {
					printf("%d ", res[i][j]);
				}
				else {
					printf("%d", res[i][j]);
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}