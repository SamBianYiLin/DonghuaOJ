#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<char, int> a, pair<char, int> b)
{
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {
    char c[200];

    while (fgets(c, sizeof(c), stdin)) {

        string str = c;
        vector<pair<char, int>> v;

        int fre[26] = { 0 };

        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];

            if (ch >= 'a' && ch <= 'z')
                ch -= 32;

            if (ch >= 'A' && ch <= 'Z')
                fre[ch - 'A']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (fre[i] > 0)
                v.push_back({ 'A' + i, fre[i] });
        }

        sort(v.begin(), v.end(), cmp);

        for (int i = 0; i < v.size(); i++)
        {
            printf("%c %d\n", v[i].first, v[i].second);
        }

        printf("\n");
    }

    return 0;
}