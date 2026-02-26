#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

static int findMultiple(int T) {
    for (int N = 7; N <= 1000000; N += 10) {  // 只枚举个位为7的数，最小从7开始
        int d = 0;
        int tmp = N;
        while (tmp > 0) {     // 统计位数
            d++;
            tmp /= 10;
        }

        long long pow10 = 1;
        for (int k = 1; k <= d - 1; k++) pow10 *= 10;  // 10^(d-1)

        int unit = N % 10;            // 这里恒为7，但写通用更清晰
        long long newNum = (long long)unit * pow10 + (N / 10);

        if (newNum == (long long)T * N) {
            return N;
        }
    }
    return -1;
}

int main() {
    int T;
    while (scanf("%d", &T) == 1) {
        int ans = findMultiple(T);
        if (ans != -1) printf("%d\n", ans);
        else printf("No\n");
    }
    return 0;
}