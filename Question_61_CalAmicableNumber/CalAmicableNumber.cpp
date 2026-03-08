#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;
int calAmicableNum(int num) {
	int sum = 0;
	for (int i = 1; i < num; i++) {
		if (num % i == 0) {
			sum += i;
		}
		else {
			continue;
		}
	}
	return sum;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int num1, num2;
		scanf("%d%d", &num1, &num2);
		if (calAmicableNum(num1) == num2 && calAmicableNum(num2) == num1) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}