#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;
bool IsPrime(int num) {
	if (num == 0 || num == 1) {
		return false;
	}
	else if (num == 2) {
		return true;
	}
	else {
		for (int i = 2; i < num; i++)
		{
			if (num % i == 0) {
				return false;
			}
		}
		return true;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		if (IsPrime(num)) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
	return 0;
}