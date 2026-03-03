#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	int n;
	scanf("%d\n", &n);
	int product = 1;
	vector<int> numSerial(n);
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		char c;
		scanf("%c",&c);
		numSerial.push_back(num);
	}
	vector<int>::iterator it;
	for (it = numSerial.begin(); it != numSerial.end(); it++) {
		if (*it % 2 == 1) {
			product *= (*it);
		}
		else {
			continue;
		}
	}

	printf("%d\n", product);
	return 0;
}