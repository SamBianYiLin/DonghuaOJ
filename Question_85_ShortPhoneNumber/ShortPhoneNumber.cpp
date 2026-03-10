#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		char c[20];
		scanf("%s", c);
		string longPhoneNum = c;
		string shortPhoneNum = "6";
		string temp = "";
		int length = longPhoneNum.size();
		for (int i = length - 1; i >= length - 5; i--){
			temp.push_back(longPhoneNum[i]);
		}
		reverse(temp.begin(), temp.end());
		shortPhoneNum += temp;
		printf("%s\n", shortPhoneNum.c_str());
	}
	return 0;
}