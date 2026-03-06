#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	int n;
	vector<int> array(10000);
	//	前两项固定,第零项为对齐项，数组下标对其数列下标
	array[0] = 0;
	array[1] = 1;
	array[2] = 5;
	while (scanf("%d", &n) > 0) {
		/*if (n > array.size() - 1) {
			for (int i = 3; i <= n; i++){
				int temp = array[i - 1] + ((i - 3) * 3 + 7);
				array[i] = temp;
			}
			printf("%d\n", array[n]);
		}
		else {
			printf("%d\n", array[n]);
		}*/
		for (int i = 3; i <= n; i++) {
			int temp = array[i - 1] + ((i - 3) * 3 + 7);
			array[i] = temp;
		}
		printf("%d\n", array[n]);
	}
	return 0;
}