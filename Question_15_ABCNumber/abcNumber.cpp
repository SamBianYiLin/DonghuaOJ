#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> SeperateNumber(int n) {
	vector<int> eachDigit;
	eachDigit.push_back(n % 10);
	eachDigit.push_back(n / 10 % 10);
	eachDigit.push_back(n / 100 % 10);
	eachDigit.push_back(n / 1000 % 10);
	eachDigit.push_back(n / 10000 % 10);
	eachDigit.push_back(n / 100000 % 10);
	return eachDigit;
}
int main() {
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) > 0) {
		int abc = a * 100 + b * 10 + c;
		int cba = c * 100 + b * 10 + a;
		int multiply = abc * cba;
		vector<int> eachDigit = SeperateNumber(multiply);
		//int counter_a = 0, counter_b = 0, counter_c = 0;
		int counter = 0;
		vector<int>::iterator it;
		printf("%d", multiply);
		for (it = eachDigit.begin(); it != eachDigit.end(); it++) {
			/*if (*it == a) {
				counter_a++;
			}
			else if (*it == b) {
				counter_b++;
			}
			else if (*it == c) {
				counter_c++;
			}
			else {
				continue;
			}*/
			if (*it == a || *it == b || *it == c) {
				counter++;
			}
			else {
				continue;
			}
		}
		/*if (counter_a == a) {
			printf("%2d", counter_a);
		}
		else if (counter_b == b) {
			printf("%2d", counter_b);
		}
		else if (counter_c == c) {
			printf("%2d", counter_c);
		}*/
		printf("%2d\n", counter);
	}
	return 0;
}