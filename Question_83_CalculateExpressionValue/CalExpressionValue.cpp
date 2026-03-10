#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
int CalExpressionVal(string expression) {
	int i = 0;
	string temp;
	stack<char> operatorChar;
	stack<int> operationInt;
	while (expression[i] != '\0') {
		if (expression[i] >= '0' && expression[i] <= '9') {
			temp.push_back(expression[i]);
			i++;
		}
		else if(expression[i] == ' ' || expression[i] == '\n') {
			i++;
			continue;
		}
		else if(expression[i] == '+' || expression[i] == '-') {
			
			if (!temp.empty()) {
				operationInt.push(stoi(temp));
				temp = "";
			}
			if (!operatorChar.empty() && operationInt.size() >= 2) {
				int op2 = operationInt.top(); operationInt.pop();
				int op1 = operationInt.top(); operationInt.pop();
				char op = operatorChar.top(); operatorChar.pop();

				if (op == '+') {
					operationInt.push(op1 + op2);
				}
				else if (op == '-') {
					operationInt.push(op1 - op2);
				}
			}
			operatorChar.push(expression[i]);
			temp = "";
			i++;
		}
	}
	operationInt.push(stoi(temp));
	while (!operatorChar.empty()) {
		int op1, op2;
		op1 = operationInt.top();
		operationInt.pop();
		op2 = operationInt.top();
		operationInt.pop();
		if (operatorChar.top() == '+') {
			operationInt.push(op1 + op2);
			operatorChar.pop();
		}
		else if (operatorChar.top() == '-') {
			operationInt.push(op2 - op1);
			operatorChar.pop();
		}
	}
	return operationInt.top();
}
int main() {
	char n[1000];
	while (fgets(n, sizeof(n), stdin)) {
		string expression = n;
		printf("%d\n", CalExpressionVal(expression));
	}
	return 0;
}