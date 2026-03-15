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
		if (chessboard[row][col] == 0)	return;
		if (blackPos[row] == col)	return;

	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &chessboard[i][j]);
		}
	}

	return 0;
}