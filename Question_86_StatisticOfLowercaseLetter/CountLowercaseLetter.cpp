#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		char chars[1000];
		scanf("%s", chars);
		string str = chars;
		int count = 0;
		for (int j = 0; j < str.size(); j++){
			if (str[j] >= 'a' && str[j] <= 'z') {
				count++;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}