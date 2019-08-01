#include<cstdio>
#include<iostream>
using namespace std;

#define csize 85

int judge(char c) {
	//如果是.返回1
	if (c == '.')
		return 1;
	//如果是数字返回2
	int t = c - '0';
	if (t >= 0 && t < 10)
		return 2;
	//如果是字母返回3
	t = c - 'a';
	if (t >= 0 && t < 26)
		return 3;
	t = c - 'A';
	if (t >= 0 && t < 26)
		return 3;
	//如果都不是
	return 0;
}

int main() {
	int N,i;
	scanf("%d\n", &N);
	char str[csize];
	bool shuzi, zimu, hefa;
	int t;
	while (N--) {
		shuzi = false;
		zimu = false;
		hefa = true;
		cin.getline(str, csize);
		for (i = 0; i < csize; i++) {
			if (str[i] == '\0')
				break;
			switch (judge(str[i]))
			{
			case 0:
				hefa = false;
				break;
			case 1:
				break;
			case 2:
				shuzi = true;
				break;
			case 3:
				zimu = true;
				break;
			}
		}
		if (i < 6) {
			printf("Your password is tai duan le.\n");
		}
		else if (hefa == false) {
			printf("Your password is tai luan le.\n");
		}
		else {
			if (shuzi&&zimu) {
				printf("Your password is wan mei.\n");
			}
			else if (zimu) {
				printf("Your password needs shu zi.\n");
			}
			else if (shuzi) {
				printf("Your password needs zi mu.\n");
			}
		}
	}
	return 0;
}