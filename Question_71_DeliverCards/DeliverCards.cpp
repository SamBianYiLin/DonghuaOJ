#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	int n;
	while (scanf("%d", &n) > 0) {
		int m = 3;
		int member = (n + m) % 4;
		for (int i = 0; i <= 3; i++) {
			int out = member + 4 * i;
			if (out > 12) {
				break;
			}
			printf("c %d ", member + 4 * i);
		}
		m--;
		member = (n + m) % 4;
		for (int i = 0; i <= 3; i++) {
			int out = member + 4 * i;
			if (out > 12) {
				break;
			}
			printf("d %d ", member + 4 * i);
		}
		m--;
		member = (n + m) % 4;
		for (int i = 0; i <= 3; i++) {
			int out = member + 4 * i;
			if (out > 12) {
				break;
			}
			printf("h %d ", member + 4 * i);
		}
		m--;
		member = (n + m) % 4;
		for (int i = 0; i <= 3; i++) {
			int out = member + 4 * i;
			if (out > 12) {
				break;
			}
			if (i == 0) {
				printf("s %d", member + 4 * i);
			}
			else {
				printf(" s %d", member + 4 * i);
			}
		}
		printf("\n");
	}
	return 0;
}