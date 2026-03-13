#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	{
		char n1[2000];
		char n2[2000];
		scanf("%s%s", n1, n2);
		bool isEqual = false;
		string num1 = n1;
		string num2 = n2;
		string num1_int = "", num1_float = "";
		string num2_int = "", num2_float = "";
		bool n1_findDot = false, n2_findDot = false;
		//	循环遍历字符串，分别读取整数、小数部分
		for (int j = 0; j < num1.size(); j++){
			if (num1[j] == '.') {
				n1_findDot = true;
			}
			else {
				if (!n1_findDot) {
					num1_int.push_back(num1[j]);
				}
				else {
					num1_float.push_back(num1[j]);
				}
			}
		}
		for (int j = 0; j < num2.size(); j++) {
			if (num2[j] == '.') {
				n2_findDot = true;
			}
			else {
				if (!n2_findDot) {
					num2_int.push_back(num2[j]);
				}
				else {
					num2_float.push_back(num2[j]);
				}
			}
		}
		bool digitAppear_1 = false, digitAppear_2 = false;
		string del0_1 = "", del0_2 = "";
		for (int j = 0; j < num1_int.size(); j++){
			if (num1_int[j] >= '1' && num1_int[j] <= '9') {
				digitAppear_1 = true;
				del0_1.push_back(num1_int[j]);
			}
			else if (digitAppear_1 && num1_int[j] == '0') {
				del0_1.push_back(num1_int[j]);
			}
			else if (!digitAppear_1) {
				continue;
			}
		}
		for (int j = 0; j < num2_int.size(); j++) {
			if (num2_int[j] >= '1' && num2_int[j] <= '9') {
				digitAppear_2 = true;
				del0_2.push_back(num2_int[j]);
			}
			else if (digitAppear_2 && num2_int[j] == '0') {
				del0_2.push_back(num2_int[j]);
			}
			else if (!digitAppear_2) {
				continue;
			}
		}

		string del0f_1 = "", del0f_2 = "";
		bool fdigitAppear_1 = false, fdigitAppear_2 = false;
		for (int j = num1_float.size() - 1; j >= 0; j--){
			if (num1_float[j] >= '1' && num1_float[j] <= '9') {
				fdigitAppear_1 = true;
				del0f_1.push_back(num1_float[j]);
			}
			else if (fdigitAppear_1 && num1_float[j] == '0') {
				del0f_1.push_back(num1_float[j]);
			}
			else if (!fdigitAppear_1) {
				continue;
			}
		}
		for (int j = num2_float.size() - 1; j >= 0; j--) {
			if (num2_float[j] >= '1' && num2_float[j] <= '9') {
				fdigitAppear_2 = true;
				del0f_2.push_back(num2_float[j]);
			}
			else if (fdigitAppear_2 && num2_float[j] == '0') {
				del0f_2.push_back(num2_float[j]);
			}
			else if (!fdigitAppear_2) {
				continue;
			}
		}

		/*int num1_stof = 0, num2_stof = 0;
		if (!num1_float.empty()) {
			num1_stof = stoi(num1_float);
		}
		if (!num2_float.empty()) {
			num2_stof = stoi(num2_float);
		}*/
		if (num1_float.empty()) {
			if (del0_1 == del0_2 && del0f_2 == "") {
			//if (del0_1 == del0_2 && num2_stof == 0) {
				isEqual = true;
			}
			else {
				isEqual = false;
			}
		}
		else if (num2_float.empty()) {
			if (del0_1 == del0_2 && del0f_1 == "") {
			//if (del0_1 == del0_2 && num1_stof == 0) {
				isEqual = true;
			}
			else {
				isEqual = false;
			}
		}
		else if (!num1_float.empty() && !num2_float.empty()) {
			if (del0_1 == del0_2 && del0f_1 == del0f_2) {
				isEqual = true;
			}
			else {
				isEqual = false;
			}
		}
		else {
			isEqual = false;
		}
		if (isEqual) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}	