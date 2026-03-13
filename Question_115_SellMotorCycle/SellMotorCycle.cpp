#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Motor
{
	string model;
	string color;
	string engineModel;
	Motor(string _model, string _color, string _eMo) {
		model = _model;
		color = _color;
		engineModel = _eMo;
	}
};
bool compare(Motor lhs, Motor rhs) {
	return lhs.model < rhs.model;
}
int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) > 0) {
		vector<string> customerRequire;
		vector<Motor> repo;
		bool found = false;
		//	读入客户需求
		for (int i = 0; i < n; i++) {
			char c[3];
			scanf("%s", c);
			string s = c;
			customerRequire.push_back(s);
		}
		//	读入仓库数据
		for (int i = 0; i < m; i++) {
			char mo[3], co[10], emo[3];
			scanf("%s %s %s", mo, co, emo);
			string model = mo; string color = co; string engineModel = emo;
			Motor m(model, color, engineModel);
			repo.push_back(m);
		}
		sort(repo.begin(), repo.end(), compare);
		for (int i = 0; i < n; i++) {
			string cusMo = customerRequire[i];
			for (int j = 0; j < m; j++) {
				if (repo[j].model == cusMo) {
					found = true;
					printf("%s %s %s\n", repo[j].model.c_str(),
						repo[j].color.c_str(), repo[j].engineModel.c_str());
				}
			}
		}
		if (!found) {
			printf("Not found!\n");
		}
	}
	return 0;
}