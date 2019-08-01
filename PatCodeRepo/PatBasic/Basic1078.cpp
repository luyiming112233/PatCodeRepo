#include<cstdio>
#include<iostream>
using namespace std;

#define size 1010

void yasuo() {
	char str[size],ch,temp;
	int num=1;
	cin.getline(str, size);
	//printf("%s\n", str);
	temp = str[0];
	for (int i = 1; i < size; i++) {
		ch = str[i];
		if (ch == '\0') {
			if (num == 1) {
				printf("%c", temp);
				temp = ch;
			}
			else {
				printf("%d%c", num, temp);
				temp = ch;
				num = 1;
			}
			break;
		}
		if (temp == ch) {
			num++;
		}
		else {
			if (num == 1) {
				printf("%c", temp);
				temp = ch;
			}
			else {
				printf("%d%c", num, temp);
				temp = ch;
				num = 1;
			}
		}
	}
	printf("\n");
}

void jieya(){
	char str[size], ch;
	int num,temp;
	cin.getline(str, size);
	for (int i = 0; i < size; i++) {
		ch = str[i];
		if (ch == '\0')
			break;
		num = ch - '0';
		//若读入的是数字
		if (num > 0 && num < 10) {
			while (true) {
				i++;
				ch = str[i];
				temp = ch - '0';
				if (temp >= 0 && temp < 10)
					num = num * 10 + temp;
				else
					break;
			}
			for (int j = 0; j < num; j++)
				printf("%c", ch);
		}
		else {
			printf("%c", ch);
		}
	}
	printf("\n");
}

int main() {
	char type;
	while (~scanf("%c", &type)) {
		getchar();
		if (type == 'C')
			yasuo();
		if (type == 'D')
			jieya();
	}
	return 0;
}