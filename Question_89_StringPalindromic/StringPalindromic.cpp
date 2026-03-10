#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	char str[1000];
	while (scanf("%s", str) > 0) {
		string origin = str;
		string reversed = str;
		reverse(reversed.begin(), reversed.end());
		if (origin == reversed) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}