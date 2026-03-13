#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct CardClass
{
	string type;
};
int GetSize(CardClass cc) {
	if (cc.type[1] == 'T') return 10;
	else if (cc.type[1] == 'J') return 11;
	else if (cc.type[1] == 'Q') return 12;
	else if (cc.type[1] == 'K') return 13;
	else if (cc.type[1] == 'A') return 14;
	else {
		return cc.type[1] - '0';
	}
}
int GetType(CardClass cc) {
	if (cc.type[0] == 'S') return 4;
	else if (cc.type[0] == 'H') return 3;
	else if (cc.type[0] == 'D') return 2;
	else if (cc.type[0] == 'C') return 1;
	else {
		return 0;
	}
}
bool compare(CardClass lhs, CardClass rhs) {
	int lcard_size = GetSize(lhs);
	int rcard_size = GetSize(rhs);
	int lcard_type = GetType(lhs);
	int rcard_type = GetType(rhs);
	if (lcard_size != rcard_size)
		return lcard_size > rcard_size;
	if (lcard_type != rcard_type)
		return lcard_type > rcard_type;
	return false;
}
struct CardsSeq
{	
	vector<CardClass> cc;
};
int main() {
	/*int n;
	scanf("%d", &n);
	vector<CardsSeq> cards;	
	for (int m = 0; m < n; m++){
		CardsSeq seq;
		for (int cardsNum = 0; cardsNum < 13 * 4; cardsNum++){
			CardClass card;
			char ct[10];
			scanf("%s", ct);
			string cardType = ct;
			card.type = cardType;
			seq.cc.push_back(card);
		}	
		cards.push_back(seq);
	}
	for (int i = 0; i < n; i++){
		sort(cards[i].cc.begin(), cards[i].cc.end(), compare);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < cards[i].cc.size(); j++){
			if ((j + 1) % 13 == 0) {
				printf("%s\n",cards[i].cc[j].type.c_str());
			}
			else {
				printf("%s ",cards[i].cc[j].type.c_str());
			}
		}
	}*/
	int n;
	scanf("%d", &n);
	for (int group = 0; group < n; group++) {
		for (int line = 0; line < 4; line++) {
			vector<CardClass> cards;
			for (int i = 0; i < 13; i++) {
				CardClass card;
				char ct[10];
				scanf("%s", ct);
				card.type = ct;
				cards.push_back(card);
			}
			sort(cards.begin(), cards.end(), compare);
			for (int i = 0; i < 13; i++) {
				if (i == 12)
					printf("%s\n", cards[i].type.c_str());
				else
					printf("%s ", cards[i].type.c_str());
			}
		}
		//	printf("\n");
		if (group != n - 1)
			printf("\n");
	}
	return 0;
}