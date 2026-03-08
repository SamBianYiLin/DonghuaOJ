#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;
void NextDay(int& year, int& month, int& day) {
	int dayOfMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	//	闰年
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		dayOfMonth[2] = 29;
	}
	if (++day > dayOfMonth[month]) {
		day = 1;
		month++;
		if (month > 12) {
			month = 1;
			year++;
		}
	}
}
int main() {
	int year, month, day, distance;
	scanf("%d%d%d%d", &year, &month, &day, &distance);
	for (int i = 0; i < distance; i++){
		NextDay(year, month, day);
	}
	printf("%d %d %d\n", year, month, day);
	return 0;
}