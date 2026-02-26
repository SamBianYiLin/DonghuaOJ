#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	int a, b;
	while (scanf("%d %d", &a, &b) > 0) {
		if (a == 0 && b == 0) {
			return 0;
		}
		for (int x = 1; x <= 100; x++) {
			for (int y = 1; y <= 100; y++) {
				if ((a * a) + (x * x) == (b * b) + (y * y)) {
					printf("%d %d\n", x, y);
				}
			}
		}
		printf("\n");
	}
	return 0;
}