#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;
bool isPrimeAndPalindrome(int num,int numOfDigit) {
	int first = 0;
	for (int i = 3; i < num; i+=2) {
		if (num % i == 0) {
			return false;
		}
		else {
			continue;
		}
	}
	vector<int> numString;
	int tempNum = num;
	numString.push_back(num % 10);
	for (int i = 0; i < numOfDigit - 1; i++) {
		numString.push_back(tempNum / 10 % 10);
		tempNum /= 10;
	}
	bool flag = true;
	for (int i = 0; i < numString.size() / 2; i++) {
		if (numString[i] != numString[numString.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}
int NumOfDigit(int num) {
	int i = 1;
	while (num / 10 != 0) {
		num /= 10;
		i++;
	}
	return i;
}
int main() {
	int start, end;
	scanf("%d %d", &start, &end);
	vector<int> res;
	for (int i = start; i <= end; i++) {
		int numOfDigit = NumOfDigit(i);
		if (isPrimeAndPalindrome(i,numOfDigit)) {
			res.push_back(i);
		}
	}
	vector<int>::iterator it;
	for(it = res.begin(); it != res.end(); it++) {
		printf("%d\n", *it);
	}
	return 0;
}