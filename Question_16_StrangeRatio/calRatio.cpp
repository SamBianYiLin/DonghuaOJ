#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> FindFactors(int num) {
	vector<int> factors;
	for (int i = 1; i <= num; i++) {
		if (num % i == 0) {
			factors.push_back(i);
		}
	}
	return factors;
}
int main() {
	int num;
	while (scanf("%d", &num) > 0) {
		double sum = 0;
		vector<int> factors = FindFactors(num);
		vector<int>::iterator it;
		for (it = factors.begin(); it != factors.end(); it++) {
			sum += *it;
		}
		double ratio = sum / (double)num;
		printf("%.2lf\n", ratio);
	}
	return 0;
}