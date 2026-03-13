//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string>
//#include<algorithm>
//using namespace std;
//int main() {
//	char c[20000];
//	fgets(c,sizeof(c),stdin);
//	string str = c;
//	if (str[str.size() - 1] == '\n') str[str.size() - 1] = '\0';
//	int maxLen = 0;
//	string longestPali = "";
//	string upperStr = str;
//	int start = 0, end = 0;
//	/*int dynamicStrLen = strWithoutSign.size();*/
//	/*for (int i = 0; i < dynamicStrLen; i++){
//		if (strWithoutSign[i] >= 'A' && strWithoutSign[i] <= 'Z' ||
//			strWithoutSign[i] >= 'a' && strWithoutSign[i] <= 'z') {
//			continue;
//		}
//		else {
//			strWithoutSign.erase(i, 1);
//			dynamicStrLen--;
//		}
//	}*/
//	/*for (int i = 2; i < str.size() - i; i++){
//		string temp = "";
//		for (int j = 0; j < i; j++){
//
//			temp.push_back(strWithoutSign[j]);
//		}
//		string reversedStr = temp;
//		reverse(temp.begin(), temp.end());
//		if (reversedStr == temp && temp.size() > maxLen) {
//			maxLen = temp.size();
//			longestPali = temp;
//		}
//		else {
//			continue;
//		}
//	}*/
//	for (int i = 0; i < upperStr.size(); i++){
//		if (upperStr[i] >= 'a' && upperStr[i] <= 'z') {
//			upperStr[i] -= 32;
//		}
//	}
//	for (int curStrLen = 2; curStrLen < upperStr.size(); curStrLen++){
//		for (int beginPos = 0; beginPos < upperStr.size() - curStrLen; beginPos++){
//			string temp = "";
//			int t_start = 0, t_end = 0;
//			int t_curlen = curStrLen;
//			for (int i = beginPos; i < t_curlen; i++) {
//				t_start = i;
//				if (t_curlen < upperStr.size()) {
//					if (upperStr[i] >= 'A' && upperStr[i] <= 'Z') {
//						temp.push_back(upperStr[i]);
//						t_end++;
//					}
//					else {
//						t_curlen++;
//					}
//				}
//				else {
//					break;
//				}
//			}
//			string reversedStr = temp;
//			reverse(temp.begin(), temp.end());
//			if (reversedStr == temp && temp.size() > maxLen) {
//				maxLen = temp.size();
//				longestPali = temp;
//				start = t_start;
//				end = t_end;
//			}
//		}			
//	}
//	string res = "";
//	for (int i = start; i <= end; i++){
//		res.push_back(str[i]);
//	}
//	printf("%s\n", res.c_str());
//	return 0;
//}