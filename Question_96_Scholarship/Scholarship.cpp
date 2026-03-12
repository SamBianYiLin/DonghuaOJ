#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct StudentInformation
{
	string name;
	int examScore;
	int classScore;
	char isLeader;
	char westernStudent;
	int paperCount;
	StudentInformation(string _name, int _examScore, int _classScore,
		char _isLeader, char _westernStudent,
		int _paperCount) {
		name = _name;
		examScore = _examScore;
		classScore = _classScore;
		isLeader = _isLeader;
		westernStudent = _westernStudent;
		paperCount = _paperCount;
	}
};
int main() {
	int n;
	bool isFirst = true;
	while (scanf("%d", &n) > 0) {
		int sum = 0; int max = INT16_MIN; string maxStu = "";
		for (int i = 0; i < n; i++) {
			char name[21];
			char examScore[3];
			char classScore[3];
			char isLeader = ' ';
			char westernStudent = ' ';
			char paperCount[2];
			int scholarship = 0;
			scanf("%s %s %s %c %c %s", name, &examScore, &classScore, &isLeader,
				&westernStudent, &paperCount);
			string nameStr = name;
			string exam_score = examScore;
			string class_score = classScore;
			string paper_count = paperCount;

			//院士奖学金：8000元，期末平均成绩高于80分，发表1篇或1篇以上论文
			if (stoi(examScore) > 80 && stoi(paper_count) >= 1) {
				scholarship += 8000;
			}
			//五四奖学金：4000元，期末平均成绩高于85分，班级评议成绩高于80分
			if (stoi(examScore) > 85 && stoi(classScore) > 80) {
				scholarship += 4000;
			}
			//成绩优秀奖：2000元，期末平均成绩高于90分
			if (stoi(examScore) > 90) {
				scholarship += 2000;
			}
			//西部奖学金：每人1000元，期末平均成绩高于85分的西部学生
			if (stoi(examScore) > 85 && westernStudent == 'Y') {
				scholarship += 1000;
			}
			//班级贡献奖：每人850元，班级评议成绩高于80分的学生干部
			if (stoi(classScore) > 80 && isLeader == 'Y') {
				scholarship += 850;
			}
			if (scholarship > max) {
				max = scholarship;
				maxStu = name;
			}
			sum += scholarship;
		}
		if (isFirst) {
			isFirst = false;
		}
		else if (!isFirst) {
			printf("\n");
		}
		printf("%s\n", maxStu.c_str());
		printf("%d\n", max);
		printf("%d\n", sum);
	}
	return 0;
}