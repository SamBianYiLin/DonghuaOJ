#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
int main() {
	char num[110] = { 0 };
	while (scanf("%s", num) > 0) {
		int counter = 0;
		int pos = 0;
		for (int i = 0; i < size(num); i++)
		{
			if (num[i] == '.') {
				pos = i;
				break;
			}
		}
		if (pos == 0) {
			printf("0\n");
			continue;
		}
		int length = 0;
		for (int i = 0; i < 110; i++) {
			if (num[i] == '\0') {
				length = i;
				break;
			}
		}
		counter = length - pos - 1;
		printf("%d\n", counter);
	}
	return 0;
}