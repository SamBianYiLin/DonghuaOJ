#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;
double total(int num) {
	double sum = 0;
	for (int i = 1; i <= num; i++){
		double t = 1.0 / (double)i;
		sum += t;
	}
	return sum;
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%.3f\n", total(n));
	return 0;
}