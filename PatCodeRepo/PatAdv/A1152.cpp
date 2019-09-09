#include<cstdio>
#include<vector>
#include<math.h>
using namespace std;

#define slen 1010
#define _CRT_SECURE_NO_WARNINGS

int L, K;
char str[slen];

int judge(int s) {
	int num = 0;
	for (int i = 0; i < K; i++)
		num = num * 10 + (str[s + i] - '0');
	if (num == 0 || num == 1) return -1;
	if (num == 2) return 2;
	for (int i = 2; i < sqrt((double)num) + 1; i++) {
		if (num%i == 0) return -1;
	}
	return num;
}

int main() {
	scanf("%d %d", &L, &K);
	scanf("\n%s", str);
	int num = -1;
	int i;
	for (i = 0; i + K <= L; i++) {
		num = judge(i);
		if (num != -1) break;
	}
	if (num == -1) printf("404");
	else {
		//printf("%d",num);
		for (int j = 0; j < K; j++) printf("%c", str[i + j]);
	}
	return 0;
}