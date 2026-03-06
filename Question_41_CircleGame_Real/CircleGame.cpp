#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int Pow(int pow) {
	int times = 1;
	if (pow == 0)
		return 1;
	else {
		for (int i = 0; i < pow; i++)
		{
			times *= 10;
		}
		return times;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	/*bool isStart = true;*/
	for (int i = 0; i < n; i++)
	{
		int counter = 0;
		vector<int> numSerial;
		for (int j = 0; j < 9; j++)
		{
			int temp;
			scanf("%d", &temp);
			numSerial.push_back(temp);
		}
		for (int i = 0; i < 9; i++)
		{
			int norm = 0;
			int reverse_int = 0;
			int pow = 8;
			int countTimes = 0;
			for (int j = i; countTimes < 9; j++)
			{
				norm += numSerial[j % 9] * Pow(pow);
				countTimes++;
				pow--;
			}
			pow = 8;
			countTimes = 0;
			/*for (int j = i + 9; countTimes < 9; j--)
			{

				reverse_int += numSerial[(9 - j)%9] * Pow(pow - (17 - j));
				countTimes++;
			}*/
			string reverse_str = to_string(norm);
			reverse(reverse_str.begin(), reverse_str.end());
			reverse_int = stoi(reverse_str);
			int difference = 0;
			if (norm >= reverse_int) {
				difference = norm - reverse_int;
			}
			else {
				difference = reverse_int - norm;
			}
			if (difference % 396 == 0) {
				counter++;
			}
		}
		/*if (!isStart) {
			printf("\n");
		}*/
		printf("%d\n", counter);
	}
	return 0;
}