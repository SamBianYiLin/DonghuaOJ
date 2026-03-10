#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	char expressionChar[20];
	int counter = 0;
	while(fgets(expressionChar,sizeof(expressionChar),stdin)){
	/*while (scanf("%s",expressionChar) != EOF) {*/
		int standardRes = 0;
		short sign = 1;
		string opStr,opStr1,opStr2;
		int op1, op2;
		string expression = expressionChar;
		int i = 0;
		while (expression[i] != '\0') {
			if (expression[i] == '+' || expression[i] == '-') {
				op1 = stoi(opStr);
				opStr = "";
				if (expression[i] == '-') {
					sign = -1;
				}
				i++;
			}
			else if (expression[i] == '\n' || expression[i] == '?') {
				break;
			}
			else if (expression[i] >= '0' && expression[i] <= '9') {
				
				opStr.push_back(expression[i]);
				i++;
			}
			else if (expression[i] == '=') {
				op2 = stoi(opStr);
				if (sign == 1) {
					standardRes = op1 + op2;
				}
				else {
					standardRes = op1 - op2;
				}
				opStr = "";
				i++;
			}

		}
		int res = 0;
		if (opStr != "") {
			res = stoi(opStr);
		}
		if (res == standardRes) {
			counter++;
		}
	}
	printf("%d\n", counter);
	return 0;
}