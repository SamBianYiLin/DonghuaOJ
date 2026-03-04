//  斐波那契数列变式
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;

int main() {
    int reborn[50] = { 1, 0, 1, 1 };
    for (int i = 4; i < 50; ++i)
        reborn[i] = reborn[i - 4] + reborn[i - 3] + reborn[i - 2]; 
    int month;
    while (scanf("%d", &month) != EOF) {
        int sum = 0;  // sum表示当月总小鼠数量
        if (month < 7) {
            for (int i = 0; i < month; ++i)
                sum += reborn[i];  // 若月数小于7，累加至当月即可
            printf("%d\n", sum);
        }
        else {
            for (int i = 0; i < 6; ++i)
                sum += reborn[month - i - 1];  // 当月总小鼠数量等于前六个月新生小鼠数量总和
            printf("%d\n", sum);
        }
    }
	return 0;
}