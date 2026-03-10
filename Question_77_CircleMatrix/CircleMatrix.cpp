#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	int n;
	bool firstCase = true;
	while (scanf("%d", &n) > 0) {
		if (!firstCase) printf("\n");
		firstCase = false;
		vector<vector<int>> matrix(n, vector<int>(n, 0));
		int curNum = 1;
		int top = 0, bottom = n-1, left = 0, right = n-1;
		while (top <= bottom && left <= right) {
			//	上边
			for (int i = left; i <= right; i++) {
				matrix[top][i] = curNum++;
			}
			top++; 
			//	右边
			for (int i = top; i <= bottom; i++) {
				matrix[i][right] = curNum++;
			}
			right--;
			//	下边
			for (int i = right; i >= left; i--) {
				matrix[bottom][i] = curNum++;
			}
			bottom--;
			//	左边
			for (int i = bottom; i >= top; i--) {
				matrix[i][left] = curNum++;
			}
			left++;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j == n - 1) {
					printf("%d", matrix[i][j]);
				}
				else {
					printf("%d ", matrix[i][j]);
				}
			}
			printf("\n");
		}
		//	printf("\n");
	}
}