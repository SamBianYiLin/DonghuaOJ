#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool IsComNum(string num) {
	//	判断合数
	bool isComNum = false;
	int num_int = stoi(num);
	for (int i = 2; i < num_int; i++) {
		if (num_int % i == 0) {
			isComNum = true;
			break;
		}
	}
	return isComNum;
}
int FindPureComNum(int num_int) {
	string num = to_string(num_int);
	string oriNum = num;
	if (!IsComNum(num)) {
		return -1;
	}
	//	判断是否为纯粹合数
	//	int num_int = stoi(num);
	while (!num.empty()) {
		num.erase(0, 1);	//	去掉最高位(下标从0开始，删除1个字符)
		if (num.empty()) {
			break;			//	删完了，说明前面都合法

		}
		if (stoi(num) == 0) {
			return stoi(oriNum);

		}

		else {

			if (IsComNum(num)) continue;

			else {

				return -1;

			}

		}

	}

	return stoi(oriNum);

}
int main() {
	vector<int> pureComNum;
	int num = 100;
	//int counter = 0;
	int res = FindPureComNum(num);
	while (pureComNum.size() < 100) {
		int pucomn = FindPureComNum(num);
		if (pucomn >= 100) {
			//counter++;
			pureComNum.push_back(pucomn);
			num++;
			//	printf("Now is %d.\n", pureComNum.size()+1);
		}
		else {
			num++;
			continue;
		}
	}
	int n;
	while (scanf("%d", &n) > 0) {
		printf("%d\n", pureComNum[n - 1]);
	}
	return 0;
}