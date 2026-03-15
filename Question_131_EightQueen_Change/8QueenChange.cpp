#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<vector<int>> chessBoard(8,vector<int>(8));
int maxSum = INT16_MIN;
vector<int> queenPos(8);
bool colUsed[8];
bool diag1[50];
bool diag2[50];
void dfs(int row, int sum) {
	if (row == 8) {
		if (sum > maxSum) maxSum = sum;
		return;
	}
	for (int col = 0; col < 8; col++) {
		if (colUsed[col]) continue;
		if (diag1[row - col + 8]) continue;
		if (diag2[row + col]) continue;

		colUsed[col] = true;
		diag1[row - col + 8] = true;
		diag2[row + col] = true;

		queenPos[row] = col;

		dfs(row + 1, sum + chessBoard[row][col]);

		colUsed[col] = false;
		diag1[row - col + 8] = false;
		diag2[row + col] = false;
	}
}
int main() {
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			scanf("%d", &chessBoard[i][j]);
		}
	}
	dfs(0, 0);
	printf("%d\n", maxSum);
	return 0;
}