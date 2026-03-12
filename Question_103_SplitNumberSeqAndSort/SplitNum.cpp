#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		char c[1000];
		vector<int> num;
		scanf("%s", c);
		string str = c;
		string temp = "";
		for (int j = 0; j < str.size(); j++){
			if (str[j] == '5') {
				if (!temp.empty()) {
					int t = stoi(temp);
					num.push_back(t);
					temp.clear();
				}
			}
			else if (j == str.size() - 1) {
				if (str[j] != '5') {
					temp.push_back(str[j]);
					int t = stoi(temp);
					num.push_back(t);
					temp.clear();
				}
			}
			else {
				temp.push_back(str[j]);
			}
		}
		sort(num.begin(), num.end());
		for (int j = 0; j < num.size(); j++){
			if (j == num.size() - 1) {
				printf("%d\n", num[j]);
			}
			else {
				printf("%d ", num[j]);
			}
		}
	}
	return 0;
}