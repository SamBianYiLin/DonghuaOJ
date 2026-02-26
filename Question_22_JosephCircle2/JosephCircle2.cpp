//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<vector>
//using namespace std;
//int main() {
//	int k;
//	while (scanf("%d", &k)>0) {
//		int size = 2 * k;
//		vector<int> queue(size + 1);
//		vector<int>::iterator it;
//		int i;
//		for (it = queue.begin(),i = 0; it != queue.end() && i < size + 1; it++ ,i++) {
//			queue[i] = i;
//		}
//		vector<int> victim;
//		for (int m = 1; m < 100000;m++) {
//			for (it = queue.begin() + 1; queue.size() > 1; it += m) {
//				if (*it > size) *it = *it % queue.size();
//				victim.push_back(*it);
//				queue.erase(it);
//			}
//			vector<int>::iterator it_victim;
//			bool flag = true;
//			for (*it = queue[k + 1], it_victim = victim.begin(); it != queue.end(); it++, it_victim++) {
//				if (*it != *it_victim) {
//					flag = false;
//				}
//				else {
//					continue;
//				}
//			}
//			if (flag) {
//				printf("%d\n", m);
//			}
//			else {
//				continue;
//			}
//		}
//	}
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

static bool ok(int k, int m) {
    int n = 2 * k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i + 1; // 1..2k

    int idx = 0; // 从编号1开始数
    for (int cnt = 0; cnt < k; cnt++) {
        idx = (idx + m - 1) % (int)a.size();
        int out = a[idx];
        if (out <= k) return false;   // 前k个出列出现人质，失败
        a.erase(a.begin() + idx);     // 删除该人
        // idx 不用变：删除后 idx 指向原来下一个人
    }
    return true;
}

int main() {
    int k;
    while (scanf("%d", &k) == 1 && k) {
        int m = 1;
        while (!ok(k, m)) m++;
        printf("%d\n", m);
    }
    return 0;
}