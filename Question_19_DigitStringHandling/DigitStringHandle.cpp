//	一定注意边界条件，尤其是输入为：5 4 3 2 1这种情况，最多只出现一次的
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	int digitNum;
	while (scanf("%d\n", &digitNum) > 0) {
		vector<int> digitString;
		for (int i = 1; i <= digitNum; i++) {
			int digit;
			scanf("%d", &digit);
			digitString.push_back(digit);
		}
		vector<int>::iterator it;
		int currentDigit=-1, counter = 1;
		int maxCounter = 1,maxDigit = digitString[0];
		for (it = digitString.begin(); it != digitString.end(); it++) {
			if (currentDigit == *it) {
				counter++;
				if (counter > maxCounter) {
					maxCounter = counter;
					maxDigit = *it;
				}
			}
			else {
				currentDigit = *it;
				counter = 1;
			}
		}
		printf("%d %d\n", maxDigit, maxCounter);
	}
	
	return 0;
}