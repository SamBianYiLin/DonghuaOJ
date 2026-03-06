#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> CalculatePower2FourDigits() {
	vector<int> powerOf2Array;
	for (int i = 31; i <= 99; i++) {
		powerOf2Array.push_back(i * i);
	}
	return powerOf2Array;
}
void SeperateNum(int num, int &thousandsDigit, 
	int &hundredsDigit ,int &tensDigit, int &unitDigit) {
	unitDigit = num % 10;
	tensDigit = num / 10 % 10;
	hundredsDigit = num / 100 % 10;
	thousandsDigit = num / 1000;
}
vector<int> FindSpecialNum(vector<int> powerOf2) {
	vector<int> specialNum;
	vector<int>::iterator it;
	for (it = powerOf2.begin(); it != powerOf2.end(); it++) {
		int thousandsDigit, hundredsDigit, tensDigit, unitDigit;
		SeperateNum(*it, thousandsDigit, hundredsDigit, tensDigit, unitDigit);
		if (thousandsDigit + tensDigit == hundredsDigit * unitDigit) {
			specialNum.push_back(*it);
		}
	}
	return specialNum;
}
int main() {
	vector<int> powerOf2 = CalculatePower2FourDigits();
	vector<int> specialNum = FindSpecialNum(powerOf2);
	int inputNum;
	while (scanf("%d", &inputNum) > 0) {
		if (inputNum > size(specialNum) || inputNum <= 0) {
			printf("ERROR!\n");
		}
		else {
			printf("%d\n", specialNum[inputNum - 1]);
		}
	}
	return 0;
}