#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
string BaseConverter(int num, int base) {
	string convertRes = "";
	while (num > 0) {
		int remainder = num % base;
		if (remainder >= 10) {
			convertRes.push_back('A' + (remainder - 10 ));
		}
		else {
			convertRes.push_back(remainder + '0');
		}
		num /= base;
	}
	reverse(convertRes.begin(), convertRes.end());
	return convertRes;
}
int main() {
	int num, base;
	while (scanf("%d%d", &num, &base) > 0) {
		if (num == 0) {
			printf("0\n");
		}
		else {
			string res = BaseConverter(num, base);
			printf("%s\n", res.c_str());
		}
	}
	return 0;
}