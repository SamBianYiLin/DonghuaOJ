#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;
int main() {
	int n;
	while (scanf("%d", &n) > 0) {
		if (n == 0 || n > 10) {
			return 0;
		}
		
		int i;
		for (i = 1; i <= n; i++) {
			if (i == 1) printf("%d", i);
			else printf("+%d", i);
		}
		for (int j = n - 1; j > 0; j--) {
			//if (j == 1) printf("%d", j);
			printf("+%d", j); 
		}
		printf("\n");
	}
	return 0;
}