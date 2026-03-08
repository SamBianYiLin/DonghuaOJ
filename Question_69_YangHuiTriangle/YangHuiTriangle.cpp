#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int level;
		scanf("%d", &level);
		vector<vector<int>> triangle(level,vector<int> (level,0));
		for (int j = 0; j < level; j++){
			triangle[j][0] = 1;
			for (int k = 1; k < level; k++) {
				triangle[j][k] = 0;
			}
		}
		//triangle[1][0] = 1; triangle[1][1] = 1;
		for (int j = 1; j < level; j++) {
			for (int k = 1; k <= j; k++){
				if (k == j) {
					triangle[j][k] = 1;
				}
				else {
					triangle[j][k] = triangle[j - 1][k - 1] + triangle[j - 1][k];
				}
				
			}
		}
		for (int j = 0; j < level; j++)
		{
			for (int k = 0; k < level; k++)
			{
				if (triangle[j][k] == 0) {
					continue;
				}
				else if(k != j){
					printf("%d ", triangle[j][k]);
				}
				else if(k == j){
					printf("%d", triangle[j][k]);
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}