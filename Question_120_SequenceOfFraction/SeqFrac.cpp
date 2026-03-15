#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
//int gcd(int a, int b) {
//
//}
struct Fraction
{
	int a;
	int b;
	Fraction(int _a, int _b) {
		a = _a;
		b = _b;
	}
};
bool compare(Fraction lhs, Fraction rhs) {
	//	return lhs.a * rhs.b < rhs.a * lhs.b;
	double lhsa = lhs.a, lhsb = lhs.b;
	double rhsa = rhs.a, rhsb = rhs.b;
	double lhs_r = lhsa / lhsb;
	double rhs_r = rhsa / rhsb;
	return lhs_r < rhs_r;
}
int gcd(int a, int b) {
	while (b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}
int main() {
	int n;
	vector<Fraction> fracs;
	scanf("%d",&n);
	if (n != 0) {
		fracs.push_back({ 0,1 });
	}
	for (int b = 1; b <= n; b++)
	{
		for (int a = 1; a <= b; a++)
		{
			if (gcd(a, b) == 1 && a != b) {
				fracs.push_back({ a,b });
			}
		}
	}
	sort(fracs.begin(), fracs.end(), compare);
	for (int i = 0; i < fracs.size(); i++)
	{
		printf("%d/%d\n", fracs[i].a, fracs[i].b);
	}
	return 0;
}