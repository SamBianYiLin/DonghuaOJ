#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	char ori[10000];
	while (scanf("%s", ori) > 0) {
		string str = ori;
		int sum = 0;
		int buffer = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				buffer = buffer * 10 + (str[i] - '0');
			}
			else if (str[i] == '+') {
				sum += buffer;
				buffer = 0;
			}
			if (str[str.size() - 1] == '\n') {
				if (i == str.size() - 2) {
					//	buffer = buffer * 10 + (str[i] - '0');
					sum += buffer;
					break;
				}
			}
			else {
				if (i == str.size() - 1) {
					sum += buffer;
					break;
				}
			}
		}
		printf("%d\n", sum);
	}

}