#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"string.h"
using namespace std;
int main() {
	int tri[200][200];
	memset(tri, 0, 40000);
	int start, lines;
	scanf("%d %d", &start, &lines);
	int current = start;
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j <= i; j++) {
			tri[i][j] = (current % 10)==0 ? current = 1:current = current % 10;
			current++;
		}
	}
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%d", tri[i][j]);
			if (j != i) {
				printf(" ");
			}
		}
		printf("\n");
	}
}