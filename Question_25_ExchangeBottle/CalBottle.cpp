#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;
int calExchangeBottle(int emptyBottle,int exchangeNum,int times) {
	if (emptyBottle == 1 || emptyBottle == 0) {
		return exchangeNum;
	}
	else if (emptyBottle == 2) {
		return exchangeNum+1;
	}
	else if(emptyBottle >= 3){
		times = emptyBottle / 3;
		exchangeNum += times;
		emptyBottle -= 3 * times;
		emptyBottle += times;
		times = emptyBottle / 3;
		return calExchangeBottle(emptyBottle, exchangeNum, times);
	}
}
int main() {
	int emptyBottle;
	while (scanf("%d", &emptyBottle) > 0) {
		if (emptyBottle == 0) {
			return 0;
		}
		int exchangeNum = 0;
		int times = emptyBottle / 3;
		printf("%d\n",calExchangeBottle(emptyBottle, exchangeNum,times));
	}
	return 0;
}