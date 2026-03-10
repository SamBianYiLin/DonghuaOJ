#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
bool compare(char lhs,char rhs) {
	return lhs < rhs;
}
int main() {
	char c[102];
	while (scanf("%s", c) > 0) {
		string str = c;
		sort(str.begin(),str.end(),compare);
		printf("%s\n", str.c_str());
	}
	return 0;
}