#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int n;
	while (scanf("%d", &n) > 0) {
		string arr;
		arr = "11";
		for (int x = 2; x <= n; x++){
			for (int i = 0; i < arr.size() - 1; i++) {
				if (arr[i] + arr[i + 1] - 2 * '0' == x) {
					arr.insert(i+1, to_string(x));
				}
			}
		}
		printf("%s\n", arr.c_str());
	}
	return 0;
}