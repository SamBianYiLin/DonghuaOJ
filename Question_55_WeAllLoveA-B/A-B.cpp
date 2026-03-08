#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int lengthA, lengthB;
		scanf("%d %d", &lengthA, &lengthB);
		vector<int> A;
		vector<int> B;
		for (int j = 0; j < lengthA; j++){	
			int t;
			scanf("%d", &t);
			A.push_back(t);
		}
		for (int j = 0; j < lengthB; j++) {
			int t;
			scanf("%d", &t);
			B.push_back(t);
		}
		int counter = 0;
		vector<int> num;
		for (int j = 0; j < lengthA; j++){
			bool found = false;
			for (int k = 0; k < lengthB; k++) {
				if (A[j] == B[k]) {
					found = true;
					counter++;
				}
			}
			if (!found) {
				num.push_back(A[j]);
			}
			found = false;
		}
		if (counter == A.size()) {
			printf("NULL\n");
		}
		else {
			sort(num.begin(), num.end());
			for (int j = 0; j < num.size(); j++) {
				printf("%d ", num[j]);
			}
			printf("\n");
		}
		
	}
	return 0;
}