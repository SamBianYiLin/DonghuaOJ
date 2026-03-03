#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
using namespace std;
int main() {
	int groupNum;
	scanf("%d", &groupNum);
	for (int i = 0; i < groupNum; i++)
	{	
		int catagories;
		double totalPrice = 0;
		scanf("%d", &catagories);
		for (int j = 0; j < catagories; j++)
		{
			char vegetable[200] = { 0 };
			scanf("%s ", vegetable);
			double quantity;
			scanf("%lf", &quantity);
			double price;
			scanf("%lf", &price);
			totalPrice += (quantity * price);
		}
		printf("%.1lf\n", totalPrice);
	}
	return 0;
}