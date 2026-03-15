#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool found = false;
string res = "";
void Hanoi(int plateNum, char from, char middle, char to, int stepNum, int& counter) {
	if (found) return;
    if (plateNum == 1) {
        counter++;
        if (counter == stepNum) {
            res = "";
            res += from;
            res += "--";
            res += to;
            found = true;
        }
        return;
    }
    Hanoi(plateNum - 1, from, to, middle, stepNum, counter);
    if (found) return;
    counter++;
    if (counter == stepNum) {
        res = "";
        res += from;
        res += "--";
        res += to;
        found = true;
        return;
    }
    Hanoi(plateNum - 1, middle, from, to, stepNum, counter);
}
int main() {
	int plateNum, stepNum;
	while (scanf("%d %d", &plateNum, &stepNum) > 0) {
        found = false;
        int counter = 0;
        res = "none";
        int totalStep = 1;
        for (int i = 0; i < plateNum; i++) {
            totalStep *= 2;
        }
        totalStep -= 1;
        if (stepNum >= 1 && stepNum <= totalStep) {
            Hanoi(plateNum, 'A', 'B', 'C', stepNum, counter);
        }
        printf("%s\n", res.c_str());
	}
	return 0;
}