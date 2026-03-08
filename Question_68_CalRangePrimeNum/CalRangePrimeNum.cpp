//	超时
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
using namespace std;
int SumOfEachDigit(int num) {
	int sum = 0;
	while (num > 0) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}
bool IsPrime(int num) {
	if (num == 1 || num == 0) {
		return false;
	}
	else if (num == 2) {
		return true;
	}
	else if (num > 10 && (num % 10) % 2 == 0 || (num % 10) % 5 == 0) {
		return false;
	}
	else if (SumOfEachDigit(num) % 3 == 0) {
		return false;
	}
	else {
		for (int i = 3; i < num; i+=2) {
			if (num % i == 0) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	int lhs, rhs;
	while (scanf("%d%d", &lhs, &rhs) > 0){
		int counter = 0;
		for (int i = lhs; i <= rhs; i++){
			if (IsPrime(i)) {
				counter++;
			}
		}
		printf("%d\n", counter);
	}
	return 0;
}