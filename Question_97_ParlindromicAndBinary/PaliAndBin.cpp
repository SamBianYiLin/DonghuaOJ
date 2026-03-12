#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
string BaseTransferToBin(int num) {
    string bin = "";
    while (num > 0) {
        bin.push_back(num % 2 + '0');
        num /= 2;
    }
    return bin;
}
int main() {
    int n;
    while (scanf("%d", &n) > 0) {
        //printf("%s", BaseTransferToBin(n).c_str());
        string octNum = to_string(n);
        string reverseNum = to_string(n);
        reverse(octNum.begin(), octNum.end());
        string binNum = BaseTransferToBin(n);
        string reverseBinNum = BaseTransferToBin(n);
        reverse(binNum.begin(), binNum.end());
        if (octNum == reverseNum && binNum == reverseBinNum) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}