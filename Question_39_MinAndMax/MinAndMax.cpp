//	一定注意：vector要定义在循环内，不然第二次输入会导致vector追加数据，而非重新录入
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	int M, N;
	bool isStart = true;
	while (scanf("%d%d", &M, &N) > 0) {
		vector<int> numSerial;
		for (int i = 0; i < M; i++)
		{
			int t;
			scanf("%d", &t);
			numSerial.push_back(t);
		}
		int max = INT16_MIN;
		int min = INT16_MAX;
		int sum = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				sum += numSerial[(i + j) % M];
			}
			if (sum > max) {
				max = sum;
			}
			if (sum < min) {
				min = sum;
			}
			
			sum = 0;
		}
		if (!isStart) {
			printf("\n");
		}
		printf("Max=%d\n", max);
		printf("Min=%d\n", min);
		isStart = false;
		//	重置值
		min = INT16_MAX;
		max = INT16_MIN;
	}
	
	return 0;
}