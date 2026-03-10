#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	char contestData[31];
	string oriData = "";
	char ch;
	//while (fgets(contestData,sizeof(contestData),stdin)) {
	while((ch = getchar()) != EOF){
		if (ch == 'W' || ch == 'L') {
			oriData.push_back(ch);
		}
		else if (ch == 'E') {
			if (oriData.empty()) {
				continue;
			}
			//	string oriData = contestData;
			/*int endPos = oriData.find('E');
			string data = oriData.substr(0, endPos);*/
			string data = oriData;
			int Wcount = 0, Lcount = 0;
			bool contestPoint = false;
			//	11分制判断
			for (int i = 0; i < data.size(); i++) {
				if (data[i] == 'W') Wcount++;
				else if (data[i] == 'L') Lcount++;
				if (Wcount >= 10 && Lcount >= 10) {
					contestPoint = true;
					//continue;
				}
				else if ((Wcount == 11 || Lcount == 11) &&
					abs(Wcount - Lcount) >= 2) {
					printf("%d:%d\n", Wcount, Lcount);
					Wcount = 0; Lcount = 0;
				}
				if (contestPoint) {
					if (abs(Wcount - Lcount) == 2) {
						printf("%d:%d\n", Wcount, Lcount);
						Wcount = 0; Lcount = 0;
						contestPoint = false;
					}
					else {
						continue;
					}
				}
			}
			if (!(Wcount == 0 && Lcount == 0)) {
				printf("%d:%d\n", Wcount, Lcount);
			}
			printf("\n");
			Wcount = 0; Lcount = 0;
			contestPoint = false;
			for (int i = 0; i < data.size(); i++) {
				if (data[i] == '\n') continue;
				if (data[i] == 'W') Wcount++;
				else if (data[i] == 'L') Lcount++;
				if (Wcount >= 20 && Lcount >= 20) {
					contestPoint = true;
					//continue;
				}
				else if ((Wcount == 21 || Lcount == 21) &&
					abs(Wcount - Lcount) >= 2) {
					printf("%d:%d\n", Wcount, Lcount);
					Wcount = 0; Lcount = 0;
					continue;
				}
				if (contestPoint) {
					if (abs(Wcount - Lcount) == 2) {
						printf("%d:%d\n", Wcount, Lcount);
						Wcount = 0; Lcount = 0;
						contestPoint = false;
					}
					else {
						continue;
					}
				}
			}
			printf("%d:%d\n", Wcount, Lcount);
			printf("\n");
			oriData = "";
		}	
	}
	return 0;
}