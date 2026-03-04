#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	int L, M;
	
	scanf("%d%d", &L, &M);
	vector<int> trees(L + 1);
	vector<int>::iterator it;
	int count = 0;
	for (it = trees.begin(); it != trees.end(); it++) {
		*it = 1;
	}
	for (int i = 0; i < M; i++)
	{
		int left, right;
		scanf("%d%d", &left, &right);
		for (int i = left; i <= right; i++) {
			if (trees[i] == 1) {
				trees[i] = 0;
				count++;
			}
		}
	}
	printf("%d", (L + 1) - count);
	return 0;
}