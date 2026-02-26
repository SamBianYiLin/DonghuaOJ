#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	int T;
	scanf("%d\n", &T);
	for (int i = 0; i < T; i++) {
		vector<int> allRes;
		int a, b;
		scanf("%d %d", &a, &b);
		int unitDigit, tensDigit;
		int res = 0;
		for (tensDigit = 0; tensDigit <= 9; tensDigit++) {
			for (unitDigit = 0; unitDigit <= 9; unitDigit++) {
				res = ( a * 100 ) + ( tensDigit * 10 ) + unitDigit;
				if (res % b == 0) {
					allRes.push_back((tensDigit * 10) + unitDigit);
				}
			}
		}
		vector<int>::iterator it;
		for (it = allRes.begin(); it != allRes.end(); it++) {
			if (it == allRes.end() - 1) {
				printf("%d\n", *it);
			}
			else {
				printf("%d ", *it);
			}
		}
	}
	return 0;
}