#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;
bool JudgeSatisfaction(int n) {
	while (n > 0) {
		if (n % 10 == 0 || n % 10 == 1) {
			n /= 10;
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}
int main() {
	int n;
	while (scanf("%d", &n) > 0) {
		//	printf(JudgeSatisfaction(n)?"Yes\n":"No\n");
		for (int i = 1; i < 2e15; i++){
			if (JudgeSatisfaction(n * i)) {
				printf("%d\n", n * i);
				break;
			}
		}
	}
}