#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool IsPalindrome(string str) {
	string origin_str = str;
	string reverse_str = str;
	reverse(reverse_str.begin(), reverse_str.end());
	if (reverse_str == origin_str) {
		return true;
	}
	else {
		return false;
	}
}
bool IsMirrored(string str) {
	string origin_str = str;
	string mirrored_str = str;
	for (int i = 0; i < mirrored_str.size(); i++)	{
		switch (mirrored_str[i]) {
		case 'A':	case 'H':	case 'I':	case 'M':	case 'O':	case 'T':
		case 'U':	case 'V':	case 'W':	case 'X':	case 'Y':	case '1':
		case '8':
			continue;
			break;
		case 'E':
			mirrored_str[i] = '3';
			break;
		case 'J':
			mirrored_str[i] = 'L';
			break;
		case 'L':
			mirrored_str[i] = 'J';
			break;
		case '0':
			mirrored_str[i] = 'O';
			break;
		case 'S':
			mirrored_str[i] = '2';
			break;
		case 'Z':
			mirrored_str[i] = '5';
			break;
		case '2':
			mirrored_str[i] = 'S';
			break;
		case '3':
			mirrored_str[i] = 'E';
			break;
		case '5':
			mirrored_str[i] = 'Z';
			break;
		default:
			return false;
			break;
		}
	}
	reverse(origin_str.begin(), origin_str.end());
	if (origin_str == mirrored_str) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	char s[50];
	while (scanf("%s", s) > 0) {
		string str = s;
		bool isPalindrome = IsPalindrome(str);
		bool isMirrored = IsMirrored(str);
		if (!isPalindrome && !isMirrored) {
			printf("%s -- is not a palindrome.\n",str.c_str());
		}
		else if (isPalindrome && !isMirrored) {
			printf("%s -- is a regular palindrome.\n", str.c_str());
		}
		else if (!isPalindrome && isMirrored) {
			printf("%s -- is a mirrored string.\n", str.c_str());
		}
		else if (isPalindrome && isMirrored) {
			printf("%s -- is a mirrored palindrome.\n", str.c_str());
		}
		printf("\n");
	}
	return 0;
}