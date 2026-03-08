#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;
bool IsPrime(int num) {
	if (num == 2) {
		return true;
	}
	else if (num == 0 || num == 1) {
		return false;
	}
	else {
		bool isPrime = true;
		for (int i = 2; i < num; i++) {
			if (num % i == 0) {
				isPrime = false;
				return isPrime;
			}
		}
		return isPrime;
	}
}
int main() {
	int m,n;
	scanf("%d%d", &m, &n); 
	int counter = 0;
	for (int i = m; i <= n; i++) {
		
		if (IsPrime(i)) {
			if (counter >= 10) {
				printf("\n");
				counter = 0;
			}
			printf("%d ", i);
			counter++;
		}
		else {
			continue;
		}
	}
	return 0;
}