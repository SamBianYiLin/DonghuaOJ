#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	int numOfNum;	
	while (scanf("%d", &numOfNum) > 0) {
		vector<int> arr(numOfNum);
		int counter = 0;
		for (int i = 0; i < numOfNum; i++){
			scanf("%d", &arr[i]);
		}
		//	最外层循环为连续数字个数，如连续一个或两个数
		for (int i = 1; i <= numOfNum; i++){
			//	中间循环为起始下标，如从下标j开始循环i位数
			for (int j = 0; j + i <= numOfNum; j++){
				int sum = 0;
				//	最内层循环为累加求和
				for (int k = 0; k < i; k++){
					sum += arr[j + k];
				}
				if (sum % 11 == 0) {
					counter++;
				}
			}
		}
		printf("%d\n", counter);
	}
	return 0;
}