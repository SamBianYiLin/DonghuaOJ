#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct MilkFarmer
{
	int price;
	int amount;
	MilkFarmer(int _price, int _amount) {
		price = _price;
		amount = _amount;
	}
};
bool compare(MilkFarmer lhs, MilkFarmer rhs) {
	return lhs.price < rhs.price;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<MilkFarmer> farmers;
	for (int x = 0; x < m; x++){
		int price, amount;
		scanf("%d %d", &price, &amount);
		MilkFarmer md(price, amount);
		farmers.push_back(md);
	}
	sort(farmers.begin(), farmers.end(), compare);
	int totalPrice = 0;
	int totalAmount = n;
	for (int i = 0; i < farmers.size(); i++){
		if (totalAmount - farmers[i].amount >= 0) {
			totalAmount -= farmers[i].amount;
			totalPrice += farmers[i].amount * farmers[i].price;
		}
		else if (totalAmount - farmers[i].amount < 0) {
			totalPrice += farmers[i].price * totalAmount;
			totalAmount = 0;
			break;
		}
	}
	printf("%d\n", totalPrice);
	return 0;
}