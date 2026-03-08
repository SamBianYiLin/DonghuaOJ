#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	int circleLength;
	while (scanf("%d", &circleLength) > 0) {
		int counter = 0;
		for (int i = 1; i < circleLength - 1; i++) {
			for (int j = 1; j < circleLength - 1 - i; j++) {
				for (int k = 1; k < circleLength - 1 - j; k++) {
					if (i + j + k == circleLength && i + j > k 
						&& i + k > j && j + k > i && i!=k &&i!=j && j!=k) {
						counter++;
					}
				}
			}
		}
		printf("%d\n", counter/6);
	}
	return 0;
}