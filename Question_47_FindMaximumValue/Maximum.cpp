#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	int numOfNum, L1, L2;
	while (scanf("%d%d%d", &numOfNum, &L1, &L2) > 0) {
		vector<int> numSerial(numOfNum);
		for (int i = 0; i < numOfNum; i++){
			scanf("%d", &numSerial[i]);
		}
		int max = INT16_MIN;
		for (int i = L1; i <= L2; i++){
			int counter = i;
			for (int j = 0; j + counter <= numOfNum; j++){
				int sum = 0;
				for (int k = 0; k < counter; k++){
					sum += numSerial[j + k];
				}
				if (sum > max) {
					max = sum;
				}
			}
			
		}
		printf("%d\n", max);
	}
	return 0;
}