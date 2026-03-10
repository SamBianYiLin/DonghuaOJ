#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
bool compare(char lhs, char rhs) {
	return lhs < rhs;
}
void Situation1(string str1, string str2) {
	set<char> sit1;
	for (int i = 0; i < str1.size(); i++) {
		sit1.insert(str1[i]);
	}
	for (int i = 0; i < str2.size(); i++) {
		sit1.insert(str2[i]);
	}
	printf("in s1 or s2:");
	set<char>::iterator it;
	for (it = sit1.begin(); it != sit1.end(); it++) {
		printf("%c", *it);
	}
	printf("\n");
}
void Situation2(string str1, string str2) {
	set<char> res;
	for (int i = 0; i < str1.size(); i++)
	{	
		for (int j = 0; j < str2.size(); j++)
		{	
			if (str1[i] == str2[j]) {
				res.insert(str1[i]);
			}
		}
	}
	//	sort(res.begin(), res.end(), compare);
	printf("in s1 and s2:");
	set<char>::iterator it;
	for (it = res.begin(); it != res.end(); it++) {
		printf("%c", *it);
	}
	printf("\n");
}
void Situation3(string str1, string str2) {
	set<char> res;
	bool isExist = false;
	for (int i = 0; i < str1.size(); i++)
	{
		for (int j = 0; j < str2.size(); j++)
		{
			if (str1[i] == str2[j]) {
				isExist = true;
			}
			else {
				continue;
			}
		}
		if (!isExist) {
			res.insert(str1[i]);
		}
		isExist = false;
	}
	isExist = false;
	for (int i = 0; i < str2.size(); i++)
	{
		for (int j = 0; j < str1.size(); j++)
		{
			if (str2[i] == str1[j]) {
				isExist = true;
			}
			else {
				continue;
			}
		}
		if (!isExist) {
			res.insert(str2[i]);
		}
		isExist = false;
	}
	printf("in s1 but not in s2 ,or in s2 but not in s1:");
	set<char>::iterator it;
	for (it = res.begin(); it != res.end(); it++) {
		printf("%c", *it);
	}
	printf("\n");
}
void Situation4(string str1, string str2) {
	vector<char> res1;
	vector<char> res2;
	bool isExist = false;
	for (char i = 'a'; i <= 'z'; i++)
	{
		for (int j = 0; j < str1.size(); j++)
		{
			if (i == str1[j]) {
				isExist = true;
				break;
			}
		}
		if (!isExist) {
			res1.push_back(i);
		}
		isExist = false;
	}
	isExist = false;
	for (char i = 'a'; i <= 'z'; i++)
	{
		for (int j = 0; j < str2.size(); j++)
		{
			if (i == str2[j]) {
				isExist = true;
			}
		}
		if (!isExist) {
			res2.push_back(i);
		}
		isExist = false;
	}
	set<char> res;
	for (int i = 0; i < res1.size(); i++)
	{
		for (int j = 0; j < res2.size(); j++)
		{
			if (res1[i] == res2[j]) {
				res.insert(res1[i]);
			}
		}
	}
	printf("not in s1 and s2:");
	set<char>::iterator it;
	for (it = res.begin(); it != res.end(); it++) {
		printf("%c", *it);
	}
	printf("\n\n");
}
int main() {
	char s1[30], s2[30];
	while (scanf("%s %s", s1, s2) > 0) {
		string str1 = s1;
		string str2 = s2;
		Situation1(str1, str2);
		Situation2(str1, str2);
		Situation3(str1, str2);
		Situation4(str1, str2);
	}
	return 0;
}