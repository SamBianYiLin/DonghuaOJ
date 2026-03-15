#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
	int n, d;
	scanf("%d %d", &n, &d);
	string res = "";
	int integerPart = n / d;
	int remainder = n % d;
	res+=to_string(integerPart);
	if (remainder == 0) {
		res += ".0";
	}
	else {
		res += '.';
		unordered_map<int, int> pos;
		string frac = "";
		int repeatStart = -1;

		while (remainder != 0) {
			if (pos.find(remainder) != pos.end()) {
				repeatStart = pos[remainder];
				break;
			}
			pos[remainder] = frac.size();
			remainder *= 10;
			int digit = remainder / d;
			frac.push_back(digit + '0');
			remainder %= d;
		}
		if (remainder == 0) {
			res += frac;
		}
		else {
			for (int i = 0; i < repeatStart; i++){
				res.push_back(frac[i]);
			}
			res.push_back('(');
			for (int i = repeatStart; i < frac.size(); i++) {
				res.push_back(frac[i]);
			}
			res.push_back(')');
		}
		
	}
	for (int i = 0; i < res.size(); i++) {
		printf("%c", res[i]);
		if ((i + 1) % 76 == 0) {
			printf("\n");
		}
	}
	if (res.size() % 76 != 0) {
		putchar('\n');
	}
	return 0;
}