//  非常重要，要多看
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;
int main() {
    int ah, am, as;
    int bh, bm, bs;
    scanf("%d %d %d %d %d %d", &ah, &am, &as, &bh, &bm, &bs);
    int plus_m = (as + bs) / 60;
    int second = as + bs - (60 * plus_m);
    int plus_h = (am + bm + plus_m) / 60;
    int minute = am + bm + plus_m - (60 * plus_h);
    int hour = ah + bh + plus_h;
    printf("%d %d %d\n", hour, minute, second);
    return 0;
}