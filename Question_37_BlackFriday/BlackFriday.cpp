#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;
void NextDay(int n, int weekStatistic[]) {
	int startYear = 1900; int month = 1; int day = 1;
	int year = startYear;
	int dayOfMonth[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	
	int count = 2;
	while (year <= startYear + n - 1) {
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
			dayOfMonth[2] = 29;
		}
		else {
			dayOfMonth[2] = 28;
		}
		while (month <= 12) {
			if (day < dayOfMonth[month]) {
				if (day == 13) {
					weekStatistic[(count) % 7]++;
					count++;
					day++;
				}
				else {
					day++;
					count++;
				}
			}
			else {
				day = 1;
				count++;
				month++;
			}
			
		}
		month = 1; day = 1;
		year++;
	}
}
int main() {
	int n;
	int weekStatistic[7] = { 0 };
	scanf("%d", &n);
	NextDay(n, weekStatistic);
	for (int i = 0; i < 7; i++) {
		if (i == 6) {
			printf("%d", weekStatistic[i]);
		}
		else{
			printf("%d ", weekStatistic[i]);
		}	
	}
	return 0;
}