#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> FindFactorNumber(int num){
	vector<int> factors;
	for (int i = 1; i < num; i++) {
		if (num % i == 0) {
			factors.push_back(i);
		}
	}
	return factors;
}
vector<int> FindStrangeNumber(int num) {
	vector<int> strangeNumbers;
	for (int i = 1; i <= num; i++) {
		int sum = 0;
		vector<int>::iterator it;
		vector<int> factors = FindFactorNumber(i);
		for (it = factors.begin(); it != factors.end(); it++) {
			// printf("%d\n", *it);
			sum += *it;
		}
		if (sum == i) {
			strangeNumbers.push_back(i);
		}
	}
	return strangeNumbers;
}
int main() {
	int num;
	scanf("%d",&num);
	vector<int> strangeNumbers = FindStrangeNumber(num);
	vector<int>::iterator it;
	for (it = strangeNumbers.begin(); it != strangeNumbers.end(); it++) {
		printf("%d\n", *it);
	}
	return 0;
}