#include<string>
#include<stdio.h>
using namespace std;
int main() {
	int num = 21;
	string binStr = "";
	string reverseStr = "";
	while (num > 0) {
		int cur = num % 2;
		binStr.push_back('0' + cur);
		num /= 2;
	}
	reverseStr = binStr;
	reverse(binStr.begin(), binStr.end());
	if (binStr == reverseStr) {
		return 1;
	}
	else {
		return 0;
	}
}
