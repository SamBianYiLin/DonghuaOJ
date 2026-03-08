#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	int testGroups;
	scanf("%d", &testGroups);
	for (int w = 0; w < testGroups; w++){
		int n;
		scanf("%d", &n);
		vector<int> missles(n);
		for (int q = 0; q < n; q++){
			int t;
			scanf("%d", &t);
			missles[q] = t;
		}
		vector<vector<int>> defeatSys(n);
		//	拦截系统遍历
		for (int i = 0; i < n; i++){
			//	每套拦截系统遍历所有序列
			int min = INT16_MAX;
			for (int j = 0; j < n; j++){
				while (missles[j] != -1) {
					if (missles[j] < min) {
						defeatSys[i].push_back(missles[j]);
					}
					else {
						continue;
					}
				}
			}
		}
	}
	return 0;
}