#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	char c[1000];
	//while (scanf("%s", c) > 0) {
	while(fgets(c,sizeof(c),stdin)){
		int counter = 0;
		vector<string> integers;
		string str = c;
		string num = "";
		/*if (str[str.size() - 1] != '\n') {
			str.push_back('\n');
		}*/
		for (int i = 0; i < str.size(); i++){
			if (str[i] >= '0' && str[i] <= '9') {
				num.push_back(str[i]);
			}
			//else if (str[i] == '\n') {
			//	if (num != "") {
			//		integers.push_back(num);
			//		counter++;
			//	}
			//}
			else {
				if (num != "") {
					integers.push_back(num);
					num = "";
					counter++;
				}
			}
		}
		if (num != "") {
			integers.push_back(num);
			counter++;
		}
		printf("%d", counter);
		for (int i = 0; i < counter; i++){
			printf(" %d", stoi(integers[i]));
		}
		printf("\n");
	}
	return 0;
}