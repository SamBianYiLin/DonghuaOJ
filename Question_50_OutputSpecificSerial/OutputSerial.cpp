#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n;
	while (scanf("%d", &n) > 0) {
		bool isStart = true;
		vector<int> initSerial(n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d",&initSerial[i]);
		}
		set<int> serial;
		vector<int>::iterator it;
		for (it = initSerial.begin(); it != initSerial.end(); it++) {
			serial.insert(*it);
		}
		//sort(serial.begin(), serial.end());
		set<int>::iterator set_it;
		for (set_it = serial.begin(); set_it != serial.end(); set_it++) {
			if (!isStart) {
				printf(" %d", *set_it);
			}
			else {
				printf("%d", *set_it);
				isStart = false;
			}
		}
		printf("\n");
	}
	return 0;
}