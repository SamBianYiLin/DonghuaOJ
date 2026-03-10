#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
using namespace std;
int main() {
	char str_c[100];
	while (fgets(str_c, sizeof(str_c), stdin)) {
		char del_c;
		scanf("%c", &del_c);
		string str = str_c;
		string newStr = "";
		for (int i = 0; str[i] != '\n'; i++) {
			if (str[i] == del_c) {
				continue;
			}
			else {
				newStr.push_back(str[i]);
			}
		}
		printf("%s\n", newStr.c_str());
		memset(str_c, 0, sizeof(str_c));
	}
	return 0;
}