#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//	进制转换 + 判断回文
bool IsBinPali(int num) {
	string binStr = "";
	string reverseStr = "";
	while (num > 0) {
		int cur = num % 2;
		binStr.push_back('0' + cur);	//	转为字符串
		num /= 2;
	}
	reverseStr = binStr;
	reverse(binStr.begin(), binStr.end());
	if (binStr == reverseStr) {
		return true;
	}
	else {
		return false;
	}
}
bool Is3Pali(int num) {
	string binStr = "";
	string reverseStr = "";
	while (num > 0) {
		int cur = num % 3;
		binStr.push_back('0' + cur);	//	转为字符串
		num /= 3;
	}
	reverseStr = binStr;
	reverse(binStr.begin(), binStr.end());
	if (binStr == reverseStr) {
		return true;
	}
	else {
		return false;
	}
}
bool Is4Pali(int num) {
	string binStr = "";
	string reverseStr = "";
	while (num > 0) {
		int cur = num % 4;
		binStr.push_back('0' + cur);	//	转为字符串
		num /= 4;
	}
	reverseStr = binStr;
	reverse(binStr.begin(), binStr.end());
	if (binStr == reverseStr) {
		return true;
	}
	else {
		return false;
	}
}
bool Is5Pali(int num) {
	string binStr = "";
	string reverseStr = "";
	while (num > 0) {
		int cur = num % 5;
		binStr.push_back('0' + cur);	//	转为字符串
		num /= 5;
	}
	reverseStr = binStr;
	reverse(binStr.begin(), binStr.end());
	if (binStr == reverseStr) {
		return true;
	}
	else {
		return false;
	}
}
bool Is6Pali(int num) {
	string binStr = "";
	string reverseStr = "";
	while (num > 0) {
		int cur = num % 6;
		binStr.push_back('0' + cur);	//	转为字符串
		num /= 6;
	}
	reverseStr = binStr;
	reverse(binStr.begin(), binStr.end());
	if (binStr == reverseStr) {
		return true;
	}
	else {
		return false;
	}
}
bool Is7Pali(int num) {
	string binStr = "";
	string reverseStr = "";
	while (num > 0) {
		int cur = num % 7;
		binStr.push_back('0' + cur);	//	转为字符串
		num /= 7;
	}
	reverseStr = binStr;
	reverse(binStr.begin(), binStr.end());
	if (binStr == reverseStr) {
		return true;
	}
	else {
		return false;
	}
}
bool IsOctPali(int num) {
	string binStr, reverseStr;
	while (num > 0) {
		binStr.push_back('0' + num % 8);
		num /= 8;
	}
	reverseStr = binStr;
	reverse(binStr.begin(), binStr.end());
	if (binStr == reverseStr) {
		return true;
	}
	else {
		return false;
	}
}
bool Is9Pali(int num) {
	string binStr, reverseStr;
	while (num > 0) {
		binStr.push_back('0' + num % 9);
		num /= 9;
	}
	reverseStr = binStr;
	reverse(binStr.begin(), binStr.end());
	if (binStr == reverseStr) {
		return true;
	}
	else {
		return false;
	}
}
bool IsDecPali(int num) {
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

//	21取二进制
//	21 % 2 = 1		21 / 2 = 10 
//	10 % 2 = 0		10 / 2 = 5
//	5 % 2  = 1		5  / 2 = 2
//	2 % 2  = 0		2  / 2 = 1
//	1 % 2  = 1		1  / 2 = 0
//	(Bin)21 = 10101

int FindDoublePalindromic(int num) {
	int counter = 0;
	if (IsBinPali(num)) {
		counter++;
	}
	if (Is3Pali(num)) {
		counter++;
	}
	if (Is4Pali(num)) {
		counter++;
	}
	if (Is5Pali(num)) {
		counter++;
	}
	if (Is6Pali(num)) {
		counter++;
	}
	if (Is7Pali(num)) {
		counter++;
	}
	if(IsDecPali(num)){
		counter++;
	}
	if (Is9Pali(num)) {
		counter++;
	}
	if (IsOctPali(num)) {
		counter++;
	}
	return counter;
}
int main() {
	int n, s;
	scanf("%d %d", &n, &s);
	vector<int> doublePali;
	int counter = 0;
	for (int i = s; counter < n ; i++)
	{
		int count = FindDoublePalindromic(i);
		if (count >= 2) {
			doublePali.push_back(i);
			counter++;
		}
		else {
			continue;
		}
	}
	vector<int>::iterator it;
	for (it = doublePali.begin(); it != doublePali.end(); it++) {
		printf("%d\n", *it);
	}
	return 0;
}