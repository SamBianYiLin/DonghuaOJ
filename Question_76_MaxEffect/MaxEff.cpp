#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[5][5];
bool used[5];
int ans;
void dfs(int row, int sum) {
    if (row == 5) {
        ans = max(ans, sum);
        return;
    }
    for (int j = 0; j < 5; j++) {
        if (!used[j]) {
            used[j] = true;
            dfs(row + 1, sum + a[row][j]);
            used[j] = false;
        }
    }
}
int main() {
    while (true) {
        if (scanf("%d", &a[0][0]) != 1)
            break;
        for (int j = 1; j < 5; j++)
            scanf("%d", &a[0][j]);
        for (int i = 1; i < 5; i++)
            for (int j = 0; j < 5; j++)
                scanf("%d", &a[i][j]);
        for (int i = 0; i < 5; i++)
            used[i] = false;
        ans = 0;
        dfs(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}