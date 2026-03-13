//  ChatGPT Generated Contents
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    int solved;
    int totalTime;
};

bool cmp(const Student& a, const Student& b) {
    if (a.solved != b.solved) return a.solved > b.solved;      // AC多的在前
    if (a.totalTime != b.totalTime) return a.totalTime < b.totalTime; // 时间少的在前
    return a.name < b.name;                                    // 名字字典序小的在前
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<Student> students;

    char name[20];
    while (scanf("%s", name) != EOF) {
        Student stu;
        stu.name = name;
        stu.solved = 0;
        stu.totalTime = 0;

        for (int i = 0; i < n; i++) {
            char status[50];
            scanf("%s", status);
            string s = status;

            int pos = s.find('(');

            if (pos != string::npos) {
                // 形如 55(1)
                int acTime = stoi(s.substr(0, pos));
                int rightParen = s.find(')');
                int wrongCount = stoi(s.substr(pos + 1, rightParen - pos - 1));

                stu.solved++;
                stu.totalTime += acTime + wrongCount * m;
            }
            else {
                // 普通整数：可能是负数、0、正数
                int x = stoi(s);
                if (x > 0) {
                    stu.solved++;
                    stu.totalTime += x;
                }
            }
        }

        students.push_back(stu);
    }

    sort(students.begin(), students.end(), cmp);

    for (int i = 0; i < (int)students.size(); i++) {
        printf("%-10s %2d %4d\n",
            students[i].name.c_str(),
            students[i].solved,
            students[i].totalTime);
    }

    return 0;
}