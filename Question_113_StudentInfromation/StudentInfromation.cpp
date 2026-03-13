#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Student
{
	int sno;
	string name;
	string gender;
	int age;
	int score;
	Student(int _sno, string _name, string _gender, int _age, int _score) {
		sno = _sno;
		name = _name;
		gender = _gender;
		age = _age;
		score = _score;
	}
};
bool compare(Student lhs, Student rhs) {
	return lhs.score < rhs.score;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<Student> students;
	for (int m = 0; m < n; m++){
		int sno;
		char _name[100];
		char _gender[10];
		int age;
		int score;
		scanf("%d %s %s %d %d", &sno, _name, _gender, &age, &score);
		string name = _name;
		string gender = _gender;
		Student s(sno, name, gender, age, score);
		students.push_back(s);
	}
	sort(students.begin(), students.end(), compare);
	for (int i = 0; i < n; i++){
		printf("%d %s %s %d %d\n", students[i].sno, students[i].name.c_str(),
			students[i].gender.c_str(), students[i].age, students[i].score);
	}
	return 0;
}