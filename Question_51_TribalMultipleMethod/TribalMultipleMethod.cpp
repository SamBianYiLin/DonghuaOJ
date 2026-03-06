#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> DealNumber(int left, int right,vector<int>& rightArr) {
	vector<int> leftArr;
	while (left >= 1) {
		leftArr.push_back(left);
		rightArr.push_back(right);
		left /= 2;
		right *= 2;
	}
	return leftArr;
}
int main() {
	int left, right;
	while (scanf("%d%d", &left, &right) > 0) {
		printf("%d*%d=", left, right);
		bool isFirst = true;
		vector<int> rightArr;
		vector<int> leftArr = DealNumber(left,right,rightArr);
		int res = 0;
		for (int i = 0; i < size(rightArr); i++)
		{	
			if (leftArr[i] % 2 == 1) {
				if (isFirst) {
					printf("%d", rightArr[i]);
					isFirst = false;
				}
				else {
					printf("+%d", rightArr[i]);
				}
				res += rightArr[i];
			}
			else {
				continue;
			}
		}
		printf("=%d\n", res);

	}
	return 0;
}