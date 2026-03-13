#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
void FloatResRemoveLastZero(string &res) {
	bool firstDigit = false;
	int i = res.size() - 1;
	while (!firstDigit && i >= 0) {
		if (res[i] == '0') {
			res.erase(i, 1);
			i--;
			continue;
		}
		else if (res[i] > '0' && res[i] <= '9') {
			firstDigit = true;
		}
	}
}
void AlignString(string &num1, string &num2,bool isFloat) {
	if (num1.size() == num2.size()) {
		return;
	}
	else {
		if (num1.size() > num2.size()) {
			if (isFloat) {
				while (num1.size() != num2.size()) {
					num2.push_back('0');
				}
			}
			else {
				while (num1.size() != num2.size()) {
					num2.insert(0, "0");
				}
			}
		}
		else {
			if (isFloat) {
				while (num1.size() != num2.size()) {
					num1.push_back('0');
				}
			}
			else {
				while (num1.size() != num2.size()) {
					num1.insert(0, "0");
				}
			}
		}
	}
}
void GetIntFloat(string num,string &num_int,string &num_float) {
	num_int = "";
	num_float = "";
	bool findDot = false;
	for (int i = 0; i < num.size(); i++){
		if (num[i] == '.') {
			findDot = true;
		}
		else {
			if (!findDot) {
				num_int.push_back(num[i]);
			}
			else {
				num_float.push_back(num[i]);
			}
		}		
	}
}
string FloatAdder(string num1_float, string num2_float,int &carry) {
	int innerCarry = 0;
	string res = "";
	AlignString(num1_float, num2_float, true);
	for (int i = num1_float.size() - 1; i >= 0; i--){
		int sum = num1_float[i] + num2_float[i] + innerCarry - 2 * '0';
		if (sum >= 10) {
			innerCarry = 1;
			sum -= 10;
			res.push_back(sum + '0');
		}
		else if (sum >= 0 && sum <= 9) {
			innerCarry = 0;
			res.push_back(sum + '0');
		}
	}
	if (innerCarry == 1) {
		carry = 1;
	}
	reverse(res.begin(), res.end());
	return res;
}
string IntegerAdder(string num1_int, string num2_int, int carry) {
	AlignString(num1_int, num2_int, false);
	string res = "";
	for (int i = 0; i < num1_int.size(); i++){
		int sum = num1_int[i] + num2_int[i] - 2 * '0' + carry;
		if (sum >= 10) {
			carry = 1;
			sum -= 10;
			res.push_back(sum + '0');
		}
		else if (sum >= 0 && sum <= 9) {
			carry = 0;
			res.push_back(sum + '0');
		}
	}
	if (carry == 1) {
		res.push_back('1');
	}
	reverse(res.begin(), res.end());
	return res;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int m = 0; m < n; m++) {
		int carry = 0;
		char nu1[1000], nu2[1000];
		scanf("%s %s", nu1, nu2);
		string num1 = nu1;
		string num2 = nu2;
		string num1_int, num1_float;
		string num2_int, num2_float;
		GetIntFloat(num1,num1_int,num1_float);
		//printf("Split num1: %s %s\n", num1_int.c_str(), num1_float.c_str());
		GetIntFloat(num2,num2_int,num2_float);
		//printf("Split num2: %s %s\n", num2_int.c_str(), num2_float.c_str());
		string floatAddRes = FloatAdder(num1_float, num2_float, carry);
		//printf("Float adder: floatRes = %s, carry = %d\n", floatAddRes.c_str(), carry);
		FloatResRemoveLastZero(floatAddRes);
		/*if (floatAddRes == "") {
			printf("Remove zero: NULL\n");
		}
		else {
			printf("Remove zero: %s\n", floatAddRes.c_str());
		}*/
		string integerAddRes = IntegerAdder(num1_int, num2_int, carry);
		//printf("Integer adder: integerRes = %s\n", integerAddRes.c_str());
		/*if (floatAddRes == "") {
			printf("Result: %s\n", integerAddRes.c_str());
		}
		else {
			printf("Result: %s.%s\n", integerAddRes.c_str(), floatAddRes.c_str());
		}*/
		if (floatAddRes == "") {
			printf("%s\n", integerAddRes.c_str());
		}
		else {
			printf("%s.%s\n", integerAddRes.c_str(), floatAddRes.c_str());
		}
	}
	return 0;
}