#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
bool IsPrime(int num) {
	for (int i = 2; i < num; i++){
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	char c[1000];
	while (scanf("%s", c) > 0) {
		priority_queue<int> pq;
		string str = c;
		if (str.size() >= 4) {
			for (int i = 0; i < str.size() - 3; i++) {
				string sub = str.substr(i, 4);
				int num = stoi(sub);
				if (IsPrime(num)) {
					pq.push(num);
				}
			}
		}
		
		if (str.size() >= 3) {
			for (int i = 0; i < str.size() - 2; i++) {
				string sub = str.substr(i, 3);
				int num = stoi(sub);
				if (IsPrime(num)) {
					pq.push(num);
				}
			}
		}
		if (str.size() >= 2) {
			for (int i = 0; i < str.size() - 1; i++) {
				string sub = str.substr(i, 2);
				int num = stoi(sub);
				if (IsPrime(num)) {
					pq.push(num);
				}
			}
		}
		for (int i = 0; i < str.size(); i++) {
			char sub = str[i];
			int num = sub - '0';
			if (IsPrime(num)) {
				pq.push(num);
			}
		}
		printf("%d\n", pq.top());
	}
	return 0;
}