#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;
struct MilkingTime
{
	int start;
	int end;
	MilkingTime(int _start, int _end) {
		start = _start;
		end = _end;
	}
};
bool compare(MilkingTime lhs, MilkingTime rhs) {
	return lhs.start < rhs.start;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<MilkingTime> farmer;
	for (int x = 0; x < n; x++){
		int _s, _e;
		scanf("%d %d", &_s, &_e);
		MilkingTime mt(_s, _e);
		farmer.push_back(mt);
	}
	int maxMilking = 0, maxSparing = 0;
	sort(farmer.begin(), farmer.end(), compare);
	for (int i = 0; i < farmer.size() - 1; i++){
		if (farmer[i].end < farmer[i + 1].start) {
			int timeDiff = farmer[i + 1].start - farmer[i].end;
			if (timeDiff > maxSparing) {
				maxSparing = timeDiff;
			}
			//	如果一个农民自己挤奶的时间最长，没有人无缝衔接
			int milkTime = farmer[i].end - farmer[i].start;
			if (milkTime > maxMilking) maxMilking = milkTime;
		}
		else if (farmer[i].end >= farmer[i + 1].start) {
			int timeDiff = farmer[i + 1].end - farmer[i].start;
			if (timeDiff > maxMilking) {
				maxMilking = timeDiff;
			}
		}
		else {
			continue;
		}
	}
	printf("%d %d\n", maxMilking, maxSparing);
	return 0;
}