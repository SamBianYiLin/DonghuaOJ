#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct candidate {
	string name;
	int counter;
};
int main() {
	vector<candidate> candidates;
	candidates.push_back({ "li",0 });
	candidates.push_back({ "zhang",0 });
	candidates.push_back({ "wang",0 });
	candidates.push_back({ "Wrong election",0 });
	for (int i = 0; i < 10; i++){
		char nameC[20];
		scanf("%s", nameC);
		string canName = nameC;
		if (canName == "zhang") {
			candidates[1].counter++;
		}
		else if (canName == "li") {
			candidates[0].counter++;
		}
		else if (canName == "wang") {
			candidates[2].counter++;
		}
		else {
			candidates[3].counter++;
		}
	}
	for (int i = 0; i < 4; i++){
		printf("%s:%d\n",candidates[i].name.c_str(), candidates[i].counter);
	}
	return 0;
}