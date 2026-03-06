#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	int a, b, c;
	bool isStart = true;
	while (scanf("%d%d%d", &a, &b, &c) > 0) {
		int d, e, f;
		vector<int> distances;
		scanf("%d %d %d", &d, &e, &f);
		for (int i = 0; i < 2400; i+=24){
			for (int j = 0; j < 2400; j+=24) {
				for (int k = 0; k < 2400; k+=24) {
					int a_time = i + a;
					int b_time = j + b;
					int c_time = k + c;
					int a_distance = a_time * d;
					int b_distance = b_time * e;
					int c_distance = c_time * f;
					if (a_distance == b_distance && b_distance == c_distance) {
						distances.push_back(a_distance);
					}
				}
			}
		}
		vector<int>::iterator it;
		int min_distance = INT16_MAX;
		for (it = distances.begin(); it != distances.end(); it++) {
			if (*it < min_distance) {
				min_distance = *it;
			}
		}
		if (!isStart) {
			printf("\n");
			isStart = false;
			printf("%d", min_distance);
		}
		else {
			printf("%d\n", min_distance);
		}
	}
	return 0;
}