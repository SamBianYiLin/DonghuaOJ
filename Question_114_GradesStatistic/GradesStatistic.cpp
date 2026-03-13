#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Student
{
	string name;
	int math;
	int politics;
	Student(string _name, int _math, int _politics) {
		name = _name;
		math = _math;
		politics = _politics;
	}
};
bool compare(Student lhs, Student rhs) {
	return lhs.math > rhs.math;
}
int main() {
	vector<Student> students;
	for (int i = 0; i < 5; i++){
		char _name[20];
		int math, politics;
		scanf("%s %d %d", _name, &math, &politics);
		string name = _name;
		Student s(name, math, politics);
		students.push_back(s);
	}
	for (int i = 0; i < 5; i++){
		printf("%s %d\n", students[i].name.c_str(),
			(students[i].math + students[i].politics) / 2);
	}
	sort(students.begin(), students.end(), compare);
	printf("%s %d %d\n", students[0].name.c_str(),students[0].math,
		students[0].politics);
	return 0;
}