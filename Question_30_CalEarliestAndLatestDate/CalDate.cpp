#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
struct Date {
	int year;
	int month;
	int day;
};
int main() {
	int n;
	scanf("%d", &n);
	vector<Date> dates;
	for (int i = 0; i < n; i++)
	{
		Date date;
		scanf("%d %d %d", &date.year, &date.month, &date.day);
		dates.push_back(date);
	}
	vector<Date>::iterator it;
	Date earliest, latest;
	earliest.year = INT16_MAX;earliest.month = INT16_MAX;earliest.day = INT16_MAX;
	latest.year = INT16_MIN; latest.month = INT16_MIN; latest.day = INT16_MIN;
	
	for (it = dates.begin(); it != dates.end(); it++) {
		if (it->year < earliest.year) {
			earliest.year = it->year;
			earliest.month = it->month;
			earliest.day = it->day;
		}
		if (it->year == earliest.year) {
			if (it->month < earliest.month) {
				earliest.month = it->month;
				earliest.day = it->day;
			}
		}
		if (it->year == earliest.year && it->month == earliest.month) {
			if (it->day < earliest.day) {
				earliest.day = it->day;
			}
		}
	}
	for (it = dates.begin(); it != dates.end(); it++) {
		if (it->year > latest.year) {
			latest.year = it->year;
			latest.month = it->month;
			latest.day = it->day;
		}
		if (it->year == latest.year) {
			if (it->month > latest.month) {
				latest.month = it->month;
				latest.day = it->day;
			}
		}
		if (it->year == latest.year && it->month == latest.month) {
			if (it->day > latest.day) {
				latest.day = it->day;
			}
		}
	}

	printf("%d %d %d\n", latest.year, latest.month, latest.day);
	printf("%d %d %d\n", earliest.year, earliest.month, earliest.day);
	return 0;
}