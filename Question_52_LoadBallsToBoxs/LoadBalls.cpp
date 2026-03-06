//  找的别人的答案，难度较大，数学推导为主！！！
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	int num;
	while (scanf("%d", &num) > 0) {
        int len = 1;
        while ((len + 1) * len / 2 + len < num) ++len;  // 通过公式计算出数组长度
        vector<int> arr(len);
        int delta = num - (len + 1) * len / 2;  // delta表示从末尾开始需要加1的元素个数
        for (int i = 0; i < len; ++i)
            arr[i] = i + 1;  // 数组初始赋值
        for (int i = 0; i < delta; ++i)
            ++arr[len - i - 1];  // 末尾开始元素加1
        for (int i = 0; i < len - 1; ++i)
            printf("%d,", arr[i]);
        printf("%d\n", arr[len - 1]);
	}
	return 0;
}