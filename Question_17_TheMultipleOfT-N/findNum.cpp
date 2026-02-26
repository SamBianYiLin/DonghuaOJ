//	难度较大，一定再次回顾
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;
int powOf10(int num) {
	if (num == 0) return 1;
	int res = 1;
	for (int i = 1; i <= num; i++) {
		res *= 10;
	}
	return res;
}
int findMultiple(int num) {
	for (int i = 7; i < 1000000; i+=10) {
		// int unitDigit = i % 10;
		int unitDigit = 7;
		/*if (i % 10 != 7) {
			continue;
		}*/
		int numCounter = 1;
		int transferNum = 0;
		int temp = i;
		while (temp / 10 != 0) {
			numCounter++;
			temp /= 10;
		}
		transferNum = (powOf10(--numCounter) * unitDigit) + (i / 10);
		//	后面的逻辑与保证可以被整除
		if (transferNum / i == num && transferNum % i == 0) {
			return i;
		}
	}
	return -1;
}
int main() {
	int num;
	while (scanf("%d", &num) > 0) {
		int flag = findMultiple(num);
		if (flag != -1) {
			printf("%d\n", flag);
		}
		else {
			printf("No\n");
		}
	}
}