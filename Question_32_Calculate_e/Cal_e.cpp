//	非常重要，一定了解该递推的代码
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;
long Fact(int num) {
	if (num == 0 || num == 1) {
		return 1;
	}
	else {
		long fact = 1;
		for (int i = num; i >= 2; i--) {
			fact *= i;
		}
		return fact;
	}
}
double Calculate_e(double threshold,int &counter) {
	/*double i = 0;
	double e = 0;
	int bottom = Fact(0);
	int preBottom = Fact(0);
	double current = 1.0 / preBottom;
	while (current > threshold) {
		e += current;
		preBottom = bottom;
		bottom++;
		current = 1.0 / (preBottom * bottom);
		counter++;
	}*/
	double e = 0;
	int bottom = 0;
	double top = 1.0;
	double first = 1.0;
	bool isFirst = true;
	double current = 1.0;
	while (current >= threshold) {
		if (isFirst) {
			e += first;
			isFirst = false;
			counter++;
			bottom = 1;
			current = top / bottom;
			continue;
		}
		counter++;
		e += current;
		current =current * ( top / (++bottom));
	}
	return e;
}
int main() {
	double threshold;
	scanf("%lf", &threshold);
	int counter = 0;
	double res = Calculate_e(threshold,counter);
	printf("%.6lf %d\n", res, counter);
	return 0;
}