#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
void dfs(int num) {
	if (num == 0)return;
	dfs(num - 1);
	printf("%c", 'A' + num - 1);
	dfs(num - 1);
}
int main() {
	int n;
	scanf("%d", &n);
	dfs(n);
	printf("\n");
	return 0;
}