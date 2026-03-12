#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
bool compare(string lhs, string rhs) {
	return lhs.size() > rhs.size();
}
int main() {
	char words_CharArr[1000];
	while (fgets(words_CharArr,sizeof(words_CharArr),stdin)) {
		string words = words_CharArr;
		vector<string> wordsArr;
		int start = 0, end = 0;
		int spaceCount = 0;
		int wholeStrSpaceCount = 0;
		for (int j = 0; j < words.size()-1; j++) {
			if (words[j] == ' ') {
				wholeStrSpaceCount++;
			}
		}
		if (wholeStrSpaceCount == words.size()-1) {
			printf("0\n");
			return 0;
		}
		if (words[words.size()] != '\n') {
			words.push_back('\n');
		}
		for (int i = 0; i < words.size(); i++) {	
			if (words[i] == ' ') {
				if (spaceCount == 0) {
					if (start == end) {
						string temp = "";
						temp.push_back(words[start]);
						wordsArr.push_back(temp);
					}
					else {
						string sub = words.substr(start, end - start + 1);
						wordsArr.push_back(sub);
					}
				}
				start = i + 1;
				spaceCount++;
				continue;
			}
			else if (words[i] >= 'a' && words[i] <= 'z' ||
				words[i] >= 'A' && words[i] <= 'Z') {
				spaceCount = 0;
				end = i;
			}
			else if (words[i] == '\n') {
				if (spaceCount == 0) {
					string sub = words.substr(start, end - start + 1);
					wordsArr.push_back(sub);
				}
				else {
					break;
				}
			}			
		}
		//sort(wordsArr.begin(), wordsArr.end(), compare);
		/*for (int i = 0; i < wordsArr.size(); i++) {
			printf("%s ", wordsArr[i].c_str());
		}*/
		int longestFirstAppearPos = 0;
		int largestSize = 0;
		for (int i = 0; i < wordsArr.size(); i++) {
			if (wordsArr[i].size() > largestSize) {
				largestSize = wordsArr[i].size();
				longestFirstAppearPos = i;
			}
			else {
				continue;
			}
		}
		if (!wordsArr.empty()) {
			printf("%d ", wordsArr[longestFirstAppearPos].size());
			printf("%s\n", wordsArr[longestFirstAppearPos].c_str());
		}
	}
	return 0;
}