#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
bool Same(int n, const vector<vector<char>>& a, const vector<vector<char>>& b) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != b[i][j]) {
				return false;
			}
		}
	}
	return true;
}
vector<vector<char>> GetReflection(int n, vector<vector<char>> origin) {
	vector<vector<char>> reflect(n, vector<char>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			reflect[i][n - 1 - j] = origin[i][j];
		}
	}
	return reflect;
}
vector<vector<char>> GetSituation1(int n, vector<vector<char>> origin) {
	vector<vector<char>> sit1(n, vector<char>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sit1[j][n - 1 - i] = origin[i][j];
		}
	}
	return sit1;
}
vector<vector<char>> GetSituation2(int n, vector<vector<char>> origin) {
	vector<vector<char>> sit2(n, vector<char>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sit2[n - 1 - i][n - 1 - j] = origin[i][j];
		}
	}
	return sit2;
}
vector<vector<char>> GetSituation3(int n, vector<vector<char>> origin) {
	vector<vector<char>> sit3(n, vector<char>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sit3[n - 1 - j][i] = origin[i][j];
		}
	}
	return sit3;
}
bool IsSituation1(int n, vector<vector<char>> origin, vector<vector<char>> transfered) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (origin[i][j] != transfered[j][n - 1 - i]) {
				return false;
			}
		}
	}
	return true;
}
bool IsSituation2(int n, vector<vector<char>> origin, vector<vector<char>> transfered) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (origin[i][j] != transfered[n - 1 - i][n - 1 - j]) {
				return false;
			}
		}
	}
	return true;
}
bool IsSituation3(int n, vector<vector<char>> origin, vector<vector<char>> transfered) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (origin[i][j] != transfered[n - 1 - j][i]) {
				return false;
			}
		}
	}
	return true;
}
bool IsSituation4(int n, vector<vector<char>> origin, vector<vector<char>> transfered) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (origin[i][j] != transfered[i][n - 1 - j]) {
				return false;
			}
		}
	}
	return true;
}
bool IsSituation5(int n, const vector<vector<char>>& reflect, const vector<vector<char>>& transfered) {
	vector<vector<char>> sit1 = GetSituation1(n, reflect);
	vector<vector<char>> sit2 = GetSituation2(n, reflect);
	vector<vector<char>> sit3 = GetSituation3(n, reflect);

	if (Same(n, sit1, transfered) ||
		Same(n, sit2, transfered) ||
		Same(n, sit3, transfered)) {
		return true;
	}
	else {
		return false;
	}
}
bool IsSituation6(int n, vector<vector<char>> origin, vector<vector<char>> transfered) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (origin[i][j] != transfered[i][j]) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	int n;
	while (scanf("%d", &n) > 0) {
		vector<vector<char>> origin(n, vector<char>(n));

		for (int i = 0; i < n; i++)
		{
			char line[25];
			scanf("%s", line);
			for (int j = 0; j < n; j++)
				origin[i][j] = line[j];
		}

		vector<vector<char>> transfered(n, vector<char>(n, '0'));
		for (int i = 0; i < n; i++)
		{
			char line[25];
			scanf("%s", line);
			for (int j = 0; j < n; j++)
				transfered[i][j] = line[j];
		}
		vector<vector<char>> reflect = GetReflection(n, origin);
		if (IsSituation1(n, origin, transfered)) {
			printf("1\n");
			continue;
		}
		else if (IsSituation2(n, origin, transfered)) {
			printf("2\n");
			continue;
		}
		else if (IsSituation3(n, origin, transfered)) {
			printf("3\n");
			continue;
		}
		else if (IsSituation4(n, origin, transfered)) {
			printf("4\n");
			continue;
		}
		else if (IsSituation5(n, reflect, transfered)) {
			printf("5\n");
			continue;
		}
		else if (IsSituation6(n, origin, transfered)) {
			printf("6\n");
			continue;
		}
		else {
			printf("7\n");
		}
	}
	return 0;
}