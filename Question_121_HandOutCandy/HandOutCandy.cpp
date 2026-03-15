#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int powOf2[] = { 1,2,4,8,16,32,64,128,256,512,1024,2048,4096 };
string TransToBin(int n) {
	string bin = "";
	while (n > 0) {
		bin.push_back(n % 2 + '0');
		n /= 2;
	}
	//reverse(bin.begin(), bin.end());
	return bin;
}
string WrongBinAdd(string num1, string num2) {
	string res = "";
	int minSize = min(num1.size(), num2.size());
	//reverse(num1.begin(), num1.end());
	//reverse(num2.begin(), num2.end());
	for (int i = 0; i < minSize; i++){
		if (num1[i] == '1' && num2[i] == '1' ||
			num1[i] == '0' && num2[i] == '0') {
			res.push_back('0');
		}
		else if (num1[i] == '1' && num2[i] == '0' ||
			num1[i] == '0' && num2[i] == '1') {
			res.push_back('1');
		}
	}
	if (num1.size() > minSize) {
		for (int i = minSize; i < num1.size(); i++)
		{
			res.push_back(num1[i]);
		}
	}
	else if (num2.size() > minSize) {
		for (int i = minSize; i < num1.size(); i++)
		{
			res.push_back(num2[i]);
		}
	}
	// reverse(res.begin(), res.end());
	return res;
}
int CalBinToOct(string bin) {
	int res = 0;
	// reverse(bin.begin(), bin.end());
	for (int i = 0; i < bin.size(); i++){
		res += (bin[i] - '0') * powOf2[i];
	}
	return res;
}
int main() {
	int n;
	/*printf("%s\n", TransToBin(50).c_str());
	printf("%s\n", TransToBin(10).c_str());
	printf("%d\n", CalBinToOct(WrongBinAdd("1001","111")));*/
	scanf("%d", &n);
	for (int x = 0; x < n; x++){
		int candies;
		scanf("%d", &candies);
		vector<int> candyValue;
		//	0号位无意义
		candyValue.push_back(-1);
		for (int y = 0; y < candies; y++){
			int val;
			scanf("%d", &val);
			candyValue.push_back(val);
		}
	}
	
	//	其他功能过于复杂，暂略
	return 0;
}