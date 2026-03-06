#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	int n;
	while (scanf("%d ", &n) > 0) {
		vector<int> numSerial;
		int counter[200] = { 0 };
		bool isStart = true;
		for (int i = 0; i < n; i++){
			int temp;
			scanf("%d", &temp);
			numSerial.push_back(temp);
		}
		vector<int>::iterator it;
		for (it = numSerial.begin(); it != numSerial.end(); it++) {
			counter[*it]++;
		}
		int max = 1;
		int max_num = 200;
		for (int i = 0; i < 200; i++){
			if (counter[i] > max) {
				max_num = i;
				max = counter[i];
			}
			else if (counter[i] == max) {
				if (i < max_num) {
					max_num = i;
				}
				else {
					continue;
				}
			}
			else {
				continue;
			}
		}
		if (!isStart) {
			printf("\n");
			isStart = false;
			printf("%d", max_num);
		}
		else {
			printf("%d\n", max_num);
		}
		
	}
	return 0;
}