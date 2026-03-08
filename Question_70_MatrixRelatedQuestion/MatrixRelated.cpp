#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	int n;
	while (scanf("%d", &n) > 0) {
		//	vector<vector<int>> matrix(n, vector<int>(n, 0));
		int matrix[100][100] = { 0 };
		for (int i = 0; i < 2 * n + 1; i++) {
			for (int j = 0; j < 2 * n + 1; j++) {
				if (i == j || i + j == 2 * n) {
					matrix[i][j] = 1;
				}
				//	右上三角
				else if (i < j) {
					//	上三角
					if (i + j < 2 * n) {
						matrix[i][j] = 2;
					}
					//	右三角
					else if (i + j > 2 * n) {
						matrix[i][j] = 5;
					}
				}
				//	左下三角
				else if (i > j) {
					//	左三角
					if (i + j < 2 * n) {
						matrix[i][j] = 4;
					}
					//	下三角
					else if (i + j > 2 * n) {
						matrix[i][j] = 3;
					}
				}
			}
		}
		for (int i = 0; i < 2 * n + 1; i++) {
			for (int j = 0; j < 2 * n + 1; j++) {
				if (matrix[i][j] == 0) {
					continue;
				}
				else if (j == 2 * n) {
					printf("%d", matrix[i][j]);
				}
				else {
					printf("%d ", matrix[i][j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}