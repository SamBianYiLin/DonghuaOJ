#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;
int main() {
	int num;
	while (scanf("%d", &num) > 0) {
		double weightSum = 0;
		double priceSum = 0;
		map<char, double> fruitWeight = { {'a',0},{'o',0},{'b',0},{'p',0} };
		const char order[4] = { 'a','o','b','p' };
		for (int i = 0; i < num; i++)
		{
			char fruit;
			double weight = 0;
			scanf(" %c", &fruit);
			scanf("%lf", &weight);
			fruitWeight[fruit] += weight;
		}
		map<char, double>::iterator it;
		printf("       apple  orange banana pineapple sum\n");
		printf("price  ");
		for (it = fruitWeight.begin(); it != fruitWeight.end(); it++) {
			for (int i = 0; i < 4; i++) {
				if (order[i] == 'a' && it->first == 'a') {
					priceSum += 1.5 * it->second;
					printf("%-7.2lf", 1.5 * it->second);
				}
				else if (order[i] == 'b' && it->first == 'b') {
					priceSum += 1.48 * it->second;
					printf("%-7.2lf", 1.48 * it->second);
				}
				else if (order[i] == 'o' && it->first == 'o') {
					priceSum += 1.4 * it->second;
					printf("%-7.2lf", 1.4 * it->second);
				}
				else if (order[i] == 'p' && it->first == 'p') {
					priceSum += 1.08 * it->second;
					printf("%-10.2lf", 1.08 * it->second);
				}
			}
		}
		printf("%-7.2lf\n", priceSum);
		printf("weight ");
		for (it = fruitWeight.begin(); it != fruitWeight.end(); it++) {
			for (int i = 0; i < 4; i++) {
				if (order[i] == 'a' && it->first == 'a') {
					weightSum += it->second;
					printf("%-7.2lf", it->second);
				}
				else if (order[i] == 'b' && it->first == 'b') {
					weightSum += it->second;
					printf("%-7.2lf", it->second);
				}
				else if (order[i] == 'o' && it->first == 'o') {
					weightSum += it->second;
					printf("%-7.2lf", it->second);
				}
				else if (order[i] == 'p' && it->first == 'p') {
					weightSum += it->second;
					printf("%-10.2lf", it->second);
				}
			}
		}
		printf("%-7.2lf\n", weightSum);
	}
	return 0;
}