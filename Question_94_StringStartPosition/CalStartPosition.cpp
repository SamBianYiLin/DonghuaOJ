#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main() {
	char s1[110];
	char s2[110];
	while (scanf("%s%s", s1, s2) > 0) {
		string s = s1;
		string subs = s2;
		/*for (int i = 0; i < s.size(); i++){
			for (int j = 0; j < subs.size(); j++){
				if (s[i] != subs[j]) {
					continue;
				}
				else {

				}
			}
		}*/
		if (s.find(subs) != string::npos) {
			printf("%d\n", s.find(subs) + 1);
		}
		else {
			printf("0\n");
		}
		memset(s1, 0, sizeof(s1));
		memset(s2, 0, sizeof(s2));
	}
	return 0;
}