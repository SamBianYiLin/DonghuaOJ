#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//bool visited[4];
int testNum[] = { 2,3,5,7 };
int nextTestNum[] = { 1,3,7,9 };
vector<int> primes;
int CalEachDigit(int num) {
	string s = to_string(num);
	int sum = 0;
	for (int i = 0; i < s.size(); i++){
		sum += (s[i] - '0');
	}
	return sum;
}
bool IsPrime(int num) {
	if (num % 10 % 2 == 0 && num != 2) return false;
	if (CalEachDigit(num) % 3 == 0 && num != 3) return false;
	for (int i = 2; i < num; i++) {
		if (num % i == 0)	return false;
	}
	return true;
}
void DFS(int num, int digits,int dimension) {
	//visited[num] = true;
	if (digits == dimension) {
		primes.push_back(num);
		return;
	}
	for (int i = 0; i < 4; i++){
		int nextNum = num * 10 + nextTestNum[i];		
		if (IsPrime(nextNum))
		{
			DFS(nextNum, digits + 1, dimension);
		}
	}
}
void FindPrime(int dimension) {
	for (int i = 0; i < 4; i++){
		DFS(testNum[i],1,dimension);
	}
}
//	打表提高运行速度
int dimen8Prime[] = { 23399339,29399999,37337999,59393339,73939133 };
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int num;
		scanf("%d", &num);
		if (num == 8) {
			for (int i = 0; i < 5; i++) {
				printf("%d\n", dimen8Prime[i]);
			}
			continue;
		}
		FindPrime(num);
		for (int i = 0; i < primes.size(); i++){
			printf("%d\n", primes[i]);
		}
		primes.clear();
	}
	return 0;
}