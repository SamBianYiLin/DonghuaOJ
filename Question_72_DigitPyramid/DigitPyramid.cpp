#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int CalMaxSum(queue<int>& toVisit, int pos) {

}
int main() {
	int lines;
	int pyramid[100][100] = { 0 };
	scanf("%d", &lines);
	for (int i = 0; i < lines; i++){
		for (int j = 0; j <= i; j++) {
			int t;
			scanf("%d", &t);
			pyramid[i][j] = t;
		}
	}
	/*for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < lines; j++)
		{
			if (pyramid[i][j] != 0) {
				printf("%d ", pyramid[i][j]);
			}
		}
		printf("\n");
	}*/
	queue<int> toVisit;
	toVisit.push(lines);
	CalMaxSum(toVisit, 0);
	return 0;
}