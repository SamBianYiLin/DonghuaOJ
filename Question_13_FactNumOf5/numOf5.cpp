//  本质即为求因子5的个数
#include<stdio.h>
using namespace std;
int main() {
    int n;
    int counter = 0;
    while (scanf("%d", &n) > 0) {
        for (int i = 1; i <= n; i++) {
            int temp = i;
            while (temp % 5 == 0) {
                counter++;
                if (temp >= 5) {
                    temp = temp / 5;
                }
                else {
                    break;
                }
            }
        }
        printf("%d\n", counter);
        counter = 0;
    }
    return 0;
}