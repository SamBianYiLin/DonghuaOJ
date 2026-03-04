#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;
int CalEachDigit(int num) {
	if (num / 10 == 0) {
		return num;
	}
	else {
		int sum = 0;
		while (num / 10 != 0) {
			sum += (num % 10);
			num /= 10;
		}
		sum += num;
		return sum;
	}
}
int FindNumber(int counter) {
	int temp = 0;
	for (int i = 0; i < counter; i++)
	{
		while (!(CalEachDigit(temp) % 17 == 0 && CalEachDigit(temp+1) % 17 == 0)) {
			temp++;
		}
		temp++;
		continue;
	}
	return temp-1;
}
int main() {
	int n;
	while(scanf("%d", &n) > 0 ) {
		printf("%d\n", FindNumber(n));
	}
	return 0;
}