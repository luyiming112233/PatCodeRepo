#include<cstdio>
#include<iostream>
using namespace std;

#define maxn 1010

char str[maxn];

bool judge(int left, int right) {
	while (left < right) {
		if (str[left] != str[right])
			return false;
		left++;
		right--;
	}
	return true;
}

int main() {
	cin.getline(str, maxn);
	int len;
	for (len = 0; len < maxn; len++) {
		if (str[len] == '\0')
			break;
	}
	if (len == 0) {
		printf("0");
		return 0;
	}
	for (int i = len; i >= 1; i--) {
		for (int j = 0; j <= len - i; j++) {
			if (judge(j, j + i-1)) {
				printf("%d", i);
				i = 0;
				break;
			}
		}
	}
	return 0;
}