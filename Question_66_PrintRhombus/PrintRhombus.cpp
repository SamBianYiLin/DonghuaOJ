#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;
void Print(int num,int curline,int &curletter) {
	if (curline == 0 || curline == 2 * num - 1) {
		for (int i = 0; i < num - 1; i++){
			printf(" ");
		}
		printf("%c",'Z' - curletter);
		curletter++;
		printf("\n");
	}
	else {
		//	打印两个字母
		//	num=3,cur=1.printspace=1
		//	num=3,cur=2,printspace=0
		for (int i = curline + 1; i < num; i++) {
			printf(" ");
		}
		for (int times = 0; times < 2; times++) {
			printf("%c", 'Z' - curletter);
			curletter++;
			if (times == 0) {
				for (int i = 0; i < 2 * curline - 1; i++) {
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}
void PrintReverse(int num, int curline, int& curletter) {
	if (curline == 0 || curline == 2 * num - 1) {
		for (int i = 0; i < num - 1; i++) {
			printf(" ");
		}
		printf("%c", 'Z' - curletter);
		curletter++;
		printf("\n");
	}
	else {
		for (int i = curline + 1; i < num; i++) {
			printf(" ");
		}
		for (int times = 0; times < 2; times++) {
			printf("%c", 'Z' - curletter);
			curletter++;
			//	num = 4; curline = 2; printspace = 3;
			//	num = 4; curline = 1; printspace = 1;
			if (times == 0) {
				for (int i = 0; i < 2 * curline - 1; i++) {
					printf(" ");
				}
			}
			
		}
		printf("\n");
	}
}
int main() {
	int num;
	int curletter = 0;
	while (scanf("%d", &num) > 0) {
		for (int i = 0; i < num; i++){
			Print(num, i, curletter);
		}
		for (int i = num - 2; i >= 0; i--) {
			PrintReverse(num, i, curletter);
		}
		curletter = 0;
		printf("\n");
	}
	return 0;
}