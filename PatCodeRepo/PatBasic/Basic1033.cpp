#include<cstdio>
#include<iostream>
using namespace std;

#define max 100010

int main() {
	char str1[max], str2[max];
	int a[128] = { 0 };
	
	
	int i,temp;

	while (cin.getline(str1, max, '\n')) {
		cin.getline(str2, max, '\n');
		//计算坏键盘表
		for (i = 0; i < max; i++) {
			if (str1[i] == '\0')
				break;
			temp = str1[i] - 'A';
			if (temp >= 0 && temp < 26)
				a[(int)('a' + temp)] = 1;
			a[(int)str1[i]] = 1;
		}
		if (a[(int)'+'] == 1) {
			for (i = 0; i < 26; i++) {
				a[(int)('A' + i)] = 1;
			}
		}

		for (i = 0; i < max; i++) {
			if (str2[i] == '\0')
				break;
			//表示坏键盘
			if (a[(int)str2[i]] != 1) {
				printf("%c", str2[i]);
			}
		}
		printf("\n");
	}
	return 0;
}