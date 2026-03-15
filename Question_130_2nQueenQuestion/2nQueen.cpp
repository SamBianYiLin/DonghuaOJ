//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//vector<vector<int>> blackqueenVec;
//vector<vector<int>> whitequeenVec;
//int count = 0;
//void DFS(vector<vector<int>> chessboard,int pos,int n) {
//	for (int i = 0; i < n; i++){
//		bool isOK = true;
//		for (int j = 0; j < pos; j++){
//			if (chessboard[i][j] == i ||
//				pos - j == chessboard[i][j] - i ||
//				pos - j == chessboard[i][j] - i ||
//				chessboard[i][j] == 0) {
//				isOK = false;
//				break;
//			}
//		}
//		if (isOK) {
//			
//		}
//	}
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//	vector<vector<int>> chessboard;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			scanf("%d", &chessboard[i][j]);
//		}
//	}
//
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n;
int counter = 0;
vector<vector<int>> chessboard;
vector<int> blackPos;	//记录黑皇后位置，blackPos[row] = col

//	黑皇后占用情况
bool blackCol[10];
bool blackDiag1[20];	//	主对角线：用row-col+n判断对角线是否有元素
bool blackDiag2[20];	//	副对角线：用row+col判断对角线是否有元素

//	白皇后占用情况
bool whiteCol[10];
bool whiteDiag1[20];	//	主对角线：用row-col+n判断对角线是否有元素
bool whiteDiag2[20];	//	副对角线：用row+col判断对角线是否有元素

void dfsWhite(int row) {
	if (row == n) {
		counter++;
		return;
	}
	for (int col = 0; col < n; col++){
		//	棋盘当前位置应当可以放置皇后
		if (chessboard[row][col] == 0)	continue;
		//	黑白皇后不能发生冲突————不在同一棋盘格内
		if (blackPos[row] == col)	continue;

		//	白皇后之间不能发生冲突————上下左右与主副对角线
		if (whiteCol[col])	continue;
		if (whiteDiag1[row - col + n])	continue;
		if (whiteDiag2[row + col])	continue;

		//	尝试将该列加入序列
		whiteCol[col] = true;
		whiteDiag1[row - col + n] = true;
		whiteDiag2[row + col] = true;

		dfsWhite(row + 1);

		whiteCol[col] = false;
		whiteDiag1[row - col + n] = false;
		whiteDiag2[row + col] = false;
	}
}

void dfsBlack(int row) {
	//	枚举完所有的黑皇后，再枚举白皇后
	if (row == n) {
		dfsWhite(0);
		return;
	}
	for (int col = 0; col < n; col++) {
		//	棋盘当前位置应当可以放置皇后
		if (chessboard[row][col] == 0)	continue;

		//	黑皇后之间不能发生冲突————上下左右与主副对角线
		if (blackCol[col])	continue;
		if (blackDiag1[row - col + n])	continue;
		if (blackDiag2[row + col])	continue;

		//	尝试将该列加入序列
		blackCol[col] = true;
		blackDiag1[row - col + n] = true;
		blackDiag2[row + col] = true;
		blackPos[row] = col;	//	把当前黑皇后的坐标信息传入

		dfsBlack(row + 1);

		blackCol[col] = false;
		blackDiag1[row - col + n] = false;
		blackDiag2[row + col] = false;
		blackPos[row] = -1;		//	把当前黑皇后的坐标信息重置
	}
}

int main() {
	scanf("%d", &n);
	chessboard.resize(n,vector<int>(n));
	blackPos.resize(n,-1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &chessboard[i][j]);
		}
	}
	dfsBlack(0);
	printf("%d\n", counter);
	return 0;
}