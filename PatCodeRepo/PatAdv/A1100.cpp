#include<cstdio>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

#define maxn 10

string lownums[13] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string highnums[13] = { "tttt","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

void printNum(char *str) {
	int num = 0;
	for (int i = 0; i < maxn; i++) {
		if (str[i] == '\0')
			break;
		num = num * 10 + str[i] - '0';
	}
	if (num < 13) {
		printf("%s\n", lownums[num].c_str());
	}
	else {
		printf("%s", highnums[num / 13].c_str());
		if (num % 13 != 0) {
			printf(" %s", lownums[num%13].c_str());
		}
		printf("\n");
	}
}

void printWord(char *str) {
	int num = 0,si=0;
	char s[maxn];
	for (int i = 0; i < maxn; i++) {
		if (str[i] == '\0') {
			s[si] = '\0';
			string stemp = s;
			for (int i = 0; i < 13; i++) {
				if (stemp == highnums[i]) {
					num += i * 13;
				}
				if (stemp == lownums[i]) {
					num += i;
				}
			}
			break;
		}
		else if(str[i]==' '){
			s[si] = '\0';
			string stemp = s;
			for (int i = 0; i < 13; i++) {
				if (stemp == highnums[i]) {
					num += i * 13;
				}
				if (stemp == lownums[i]) {
					num += i;
				}
			}
			si = 0;
		}
		else {
			s[si] = str[i];
			si++;
		}
	}
	printf("%d\n", num);
}

int main() {
	int N;
	char str[maxn];
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		cin.getline(str, maxn);
		if (str[0] >= '0' && str[0] <= '9') {
			printNum(str);
		}
		else {
			printWord(str);
		}
	}
	return 0;
}