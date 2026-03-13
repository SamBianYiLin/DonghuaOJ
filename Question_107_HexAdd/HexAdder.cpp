#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int Trans(char c) {
	int res = 0;
	if (c >= 'a' && c <= 'f') {
		switch (c) {
		case 'a':
			res = 10;
			break;
		case 'b':
			res = 11;
			break;
		case 'c':
			res = 12;
			break;
		case 'd':
			res = 13;
			break;
		case 'e':
			res = 14;
			break;
		case 'f':
			res = 15;
			break;
		}
	}
	else {
		res = c - '0';
	}
	return res;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int m = 0; m < n; m++){
		char c1[10], c2[10];
		scanf("%s %s", c1, c2);
		string hex1 = c1;
		string hex2 = c2;
		int carry = 0;
		string res = "";
		if (hex1.size() != hex2.size()) {
			if (hex1.size() > hex2.size()) {
				while (hex1.size() != hex2.size()) {
					hex2.insert(0, "0");
				}
			}
			else if (hex1.size() < hex2.size()) {
				while (hex1.size() != hex2.size()) {
					hex1.insert(0, "0");
				}
			}
		}
		for (int i = hex1.size() - 1; i >= 0; i--){
			int hex1_int, hex2_int;
			hex1_int = Trans(hex1[i]);
			hex2_int = Trans(hex2[i]);
			/*if (hex1[i] >= '0' && hex1[i] <= '9') {
				hex1_int = hex1[i] - '0';
			}
			else {
				hex1_int = 10 + (hex1[i] - 'a' - '0');
			}
			if (hex2[i] >= '0' && hex2[i] <= '9') {
				hex2_int = hex2[i] - '0';
			}
			else {
				hex2_int = 10 + (hex2[i] - 'a');
			}*/
			int sum = hex1_int + hex2_int + carry;
			char s_c;
			if (sum > 9 && sum <= 15) {
				s_c = 'a' + (sum - 10);
				carry = 0;
				res.push_back(s_c);
			}
			else if (sum > 15) {
				carry = 1;
				sum -= 16;
				if (sum > 9 && sum <= 15) {
					s_c = 'a' + (sum - 10);
					res.push_back(s_c);
				}
				else if(sum >= 0 && sum <= 9){
					res.push_back(sum + '0');
				}
			}
			else if (sum >= 0 && sum <= 9) {
				carry = 0;
				res.push_back(sum + '0');
			}
		}
		if (carry != 0) {
			res.push_back('1');
		}
		reverse(res.begin(), res.end());
		printf("%s\n", res.c_str());
	}
	return 0;
}