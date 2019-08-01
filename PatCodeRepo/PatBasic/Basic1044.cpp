#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

#define max 30

int main() {
	const char *cnum1[13] = { "tret" ,"jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
	const char *cnum2[13] = { "0" ,"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	int n,temp,num;
	char str[max];
	scanf("%d\n", &n);
	while (n--) {
		cin.getline(str, max);
		temp = str[0] - '0';
		//表示是地球文
		if (temp >= 0 && temp < 10) {
			num = 0;
			for (int i = 0; i < max; i++) {
				if (str[i] == '\0')
					break;
				num = num * 10 + (str[i] - '0');
			}
			if (num / 13 > 0) {
				printf("%s ", cnum2[num / 13]);
			}
			printf("%s\n", cnum1[num % 13]);
		}
		//火星文
		else {
			int k,v=0,sum=0;
			bool ge = false;
			char t[5];
			for (k = 0; k < max; k++) {
				if (str[k] == '\0') {
					t[v] = '\0';
					ge = false;
					//判断个位
					for (int i = 0; i < 13; i++) {
						if (strcmp(t, cnum1[i]) == 0) {
							ge = true;
							sum += i;
						}
					}
					//判断十位
					if (ge == false) {
						for (int i = 1; i < 13; i++) {
							if (strcmp(t, cnum2[i]) == 0) {
								ge = true;
								sum = sum + (13 * i);
							}
						}
					}
					break;
				}
				if (str[k] != (int)(' ')) {
					t[v++] = str[k];
				}
				else {
					t[v] = '\0';
					ge = false;
					//判断个位
					for (int i = 0; i < 13; i++) {
						if (strcmp(t, cnum1[i]) == 0) {
							ge = true;
							sum += i;
						}
					}
					//判断十位
					if (ge == false) {
						for (int i = 1; i < 13; i++) {
							if (strcmp(t, cnum2[i]) == 0) {
								ge = true;
								sum = sum+(13*i);
							}
						}
					}
					v = 0;
				}
			}

			printf("%d\n", sum);
		}
	}
	return 0;
}