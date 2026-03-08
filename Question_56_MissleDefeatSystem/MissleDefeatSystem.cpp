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
		vector<int> missiles(n);
		for (int q = 0; q < n; q++){
			int t;
			scanf("%d", &t);
			missiles[q] = t;
		}
        // systems[i] 表示第 i 套系统当前最后一次拦截的高度
        vector<int> systems;

        for (int i = 0; i < n; i++) {
            int h = missiles[i];

            int bestIndex = -1;
            int bestTail = 1000000000;  // 找 >= h 的最小尾值

            for (int j = 0; j < (int)systems.size(); j++) {
                if (systems[j] >= h && systems[j] < bestTail) {
                    bestTail = systems[j];
                    bestIndex = j;
                }
            }

            if (bestIndex == -1) {
                // 没有系统能接，新增一套
                systems.push_back(h);
            }
            else {
                // 让最合适的那套系统接这个导弹
                systems[bestIndex] = h;
            }
        }

        printf("%d\n", (int)systems.size());
	}
	return 0;
}