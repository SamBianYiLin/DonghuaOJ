#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	char ori[20];
	while (scanf("%s", ori) > 0) {
		string originStr = ori;
		string translateStr = "";
		bool needTrans = false;
		int repeatTimes = 0;
		for (int i = 0; i < originStr.size(); i++){
			if (originStr[i] >= '0' && originStr[i] <= '9') {
				if (needTrans && repeatTimes > 0) {
					for (int j = 0; j < repeatTimes; j++) {
						translateStr.push_back(originStr[i]);
					}
					needTrans = false;
				}
				else {
					needTrans = true;
					//	translateStr.push_back(originStr[i]);
					repeatTimes = originStr[i] + 1 - '0';
				}
			}
			else {
				if (needTrans && repeatTimes > 0) {
					for (int j = 0; j < repeatTimes; j++) {
						translateStr.push_back(originStr[i]);
					}
					needTrans = false;
				}
				else {
					needTrans = false;
					translateStr.push_back(originStr[i]);
				}
			}
		}
		int length = translateStr.size();
		int spaceCounter = 0;
		int pos = 3;
		if (length > 3) {
			while (pos < translateStr.size()) {
				if (spaceCounter % 3 == 0) {
					translateStr.insert(pos," ");
					pos++;
					//spaceCounter++;
				}
				pos++;
				spaceCounter++;
			}
			printf("%s\n", translateStr.c_str());
		}
		else {
			printf("%s\n", translateStr.c_str());
		}	
	}
	return 0;
}