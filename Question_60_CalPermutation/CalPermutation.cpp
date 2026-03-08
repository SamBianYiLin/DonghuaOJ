#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;
int fact(int n) {
	int res = 1;
	while (n > 0) {
		res *= n;
		n--;
	}
	return res;
}
int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	int res = fact(m) / fact(m - n);
	printf("%d\n", res);
	return 0;
}