#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;
vector<vector<int>> chessBoard;
int n = 0;
vector<int> carPos;
bool check(int row, int col) {
	// 上
	for (int r = row - 1; r >= 0; r--) {
		if (chessBoard[r][col] == 0) break;
		if (carPos[r * n + col]) return false;
	}

	// 下
	for (int r = row + 1; r < n; r++) {
		if (chessBoard[r][col] == 0) break;
		if (carPos[r * n + col]) return false;
	}

	// 左
	for (int c = col - 1; c >= 0; c--) {
		if (chessBoard[row][c] == 0) break;
		if (carPos[row * n + c]) return false;
	}

	// 右
	for (int c = col + 1; c < n; c++) {
		if (chessBoard[row][c] == 0) break;
		if (carPos[row * n + c]) return false;
	}

	return true;
}
void dfs(int pos,int currentCarNum,int chessNum,int &counter) {
	if (currentCarNum + (n * n - pos) < chessNum) return;
	if (currentCarNum > chessNum) return;
	if (pos == n * n) {
		if (currentCarNum == chessNum) counter++;
		return;
	}

	int row = pos / n;
	int col = pos % n;

	// 当前行不放车
	dfs(pos + 1, currentCarNum, chessNum, counter);

	// 当前行放车
	if (chessBoard[row][col] == 1 && check(row, col)) {
		carPos[row * n + col] = 1;

		dfs(pos + 1, currentCarNum + 1, chessNum, counter);

		carPos[row * n + col] = 0;
	}
}
int main() {
	scanf("%d", &n);
	chessBoard.resize(n, vector<int>(n));
	//	0->没车;	1->有车;
	carPos.resize(n * n, 0);
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < n; j++)	{
			scanf("%d", &chessBoard[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)	{
		int counter = 0;
		dfs(0, 0, i, counter);
		printf("%d\n", counter);
	}
	return 0;
}