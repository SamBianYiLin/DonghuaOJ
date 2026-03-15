#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
int n;
vector<vector<int>> tests;
vector<int> wellChips;
bool chip[30] = { false };
bool check() {
	for (int i = 0; i < n; i++)	{
		if (!chip[i]) continue;	//	坏芯片测试结果不可信
		for (int j = 0; j < n; j++)	{
			if (i == j)	continue;
			if (tests[i][j] != chip[j]) {
				return false;
			}
		}
	}
	return true;
}
void dfs(int curChip) {
	if (curChip == n) {
		int good = 0;
		for (int i = 0; i < n; i++)	{
			if (chip[i]) good++;
		}
		if (good <= n / 2) {
			return;
		}
		if (check()) {
			for (int i = 0; i < n; i++)	{
				if (chip[i]) {
					wellChips.push_back(i + 1);
				}
			}
		}
		return;
	}
	chip[curChip] = true;
	dfs(curChip + 1);

	chip[curChip] = false;
	dfs(curChip + 1);
}
int main() {
	scanf("%d", &n);
	tests.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int t; scanf("%d", &t);
			tests[i][j] = t;
		}
	}
	dfs(0);
	for (int i = 0; i < wellChips.size(); i++) {
		if (i == 0) {
			printf("%d ", wellChips[i]);
		}
		else {
			printf("%d ", wellChips[i]);
		}
	}
	return 0;
}