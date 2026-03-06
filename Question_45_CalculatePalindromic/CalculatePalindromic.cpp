#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
bool IsPalindromic(int num) {
	int origin = num;
	int reverse = 0;
	while (num > 0) {
		reverse = reverse * 10 + num % 10;
		num /= 10;
	}
	if (reverse == origin) {
		return true;
	}
	else {
		return false;
	}
}
int ReverseIntNum(int num) {
	string origin = to_string(num);
	reverse(origin.begin(),origin.end());
	int reverseNum = stoi(origin);
	return reverseNum;
}
void CalculatePalindromic(int num) {
	int reverseNum = ReverseIntNum(num);
	int sum = num + reverseNum;
	printf("%d+%d=%d\n", num, reverseNum, sum);
	if (!IsPalindromic(sum)) {
		CalculatePalindromic(sum);
	}
	else {
		return;
	}
}
int main() {
	int input_num;
	while (scanf("%d", &input_num) > 0) {
		if (input_num == 0) {
			return 0;
		}
		else {
			CalculatePalindromic(input_num);
		}
	}
	return 0;
}