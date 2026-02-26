#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;
//	判断是否为质数
bool IsPrime(int num) {
	for (int i = 3; i < num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}
//	判断是否为回文数
//	forEx:135
bool IsParlidrome(int num) {
	int origin = num;
	int reverse = 0;
	while (num > 0) {
		reverse = reverse * 10 + num % 10;
		num /= 10;
	}
	if (origin == reverse) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	int start, end;
	scanf("%d %d", &start, &end);
	for (int i = start; i <= end; i++) {
		if (IsParlidrome(i) && IsPrime(i)) {
			printf("%d\n", i);
		}
	}
	return 0;
}