#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;
int CalSum(int num) {
	if (num / 10 == 0) {
		return num;
	}
	else {
		int sum = 0;
		while (num / 10 != 0) {
			sum += num % 10;
			num /= 10;
		}
		sum += num;
		return sum;
	}
}
int main() {
	int num;
	while (scanf("%d", &num) > 0) {
		printf("%d\n",CalSum(num));
	}
	return 0;
}