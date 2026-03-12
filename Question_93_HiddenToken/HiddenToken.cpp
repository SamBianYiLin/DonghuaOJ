#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main() {
	int n; 
	string str = "";
	char ch;
	int count = 0;
	scanf("%d", &n);
	while ((ch = getchar()) != EOF) {
		if (count < n) {
			if (ch == '\n') continue;
			str.push_back(ch);
			count++;
		}
		else if (count == n) {
			break;
		}
	}
		vector<string> arr;
		priority_queue<string, vector<string>, greater<string>> getMin;
		for (int i = 0; i < n; i++) {
			string t = "";
			for (int j = i + 1; j <= i + n; j++) {
				char temp = str[(j - 1 + n) % n];
				t.push_back(temp);
			}
			//	t.push_back(i);
			arr.push_back(t);
			getMin.push(t);
		}
		string minStr = getMin.top();
		int position = -1;
		for (int i = 0; i < n; i++) {
			if (minStr == arr[i]) {
				position = i;
				break;
			}
		}
		printf("%d\n", position);
	return 0;
}