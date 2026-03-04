#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;
int getResult(int a, int b, int weishu[])
{
    //请完成此函数
    int num = 0;
    int counter = 0;
    /*
    for (int i = 1; i <= 10000; i*=10) {    
        int t = i;
        while (t > 0) {
            num += a * t;
            t /= 10;
        }
        int wholeNum;
        for (int j = 0; j < 100; j++) {
            wholeNum = num * 100 + j ;
            if (wholeNum % b == 0) {
                weishu[counter] = j;
                counter++;
                while (weishu[find] == '\0') {
                    weishu[find] = j;
                }
            }
            
        }
        num = 0;
    }
    */
    for (int j = 0; j < 100; j++) {
        int wholeNum = a * 100 + j;
        if (wholeNum % b == 0) {
            weishu[counter++] = j;
        }
    }
    sort(weishu, weishu+counter);
    return counter;
}
int main()
{
    int a, b, weishu[100], count, i;
    scanf("%d%d", &a, &b);
    count = getResult(a, b, weishu);
    for (i = 0; i < count; i++)
    {
        if (i > 0)
            printf(" ");
        printf("%02d", weishu[i]);
    }
    printf("\n");
    return 0;
}
