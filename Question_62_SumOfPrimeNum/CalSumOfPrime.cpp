#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;
bool IsPrime(int num) {
	if (num == 2) {
		return true;
	}
	else if (num == 1) {
		return false;
	}
	else {
		for (int i = 2; i < num; i++) {
			if (num % i == 0) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int m = 0; m < n; m++)
	{
		int counter = 0;
		int sum;
		scanf("%d", &sum);
		for (int i = 1; i < sum/2; i++){
			int rest = sum - i;
			if (IsPrime(i) && IsPrime(rest)) {
				counter++;
			}
		}
		printf("%d\n", counter);
	}
	return 0;
}