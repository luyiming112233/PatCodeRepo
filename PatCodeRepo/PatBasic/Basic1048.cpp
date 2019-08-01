#include<cstdio>

int char2int(char c) {
	int v = 0;
	switch (c)
	{
	case '0':v = 0; break;
	case '1':v = 1; break;
	case '2':v = 2; break;
	case '3':v = 3; break;
	case '4':v = 4; break;	
	case '5':v = 5; break;
	case '6':v = 6; break;
	case '7':v = 7; break;
	case '8':v = 8; break;	
	case '9':v = 9; break;
	case 'J':v = 10; break;
	case 'Q':v = 11; break;
	case 'K':v = 12; break;
	default:v = -1; break;
	}
	return v;
}

char int2char(int v) {
	char c;
	switch (v)
	{
	case 0:c = '0'; break;
	case 1:c = '1'; break;
	case 2:c = '2'; break;
	case 3:c = '3'; break;
	case 4:c = '4'; break;
	case 5:c = '5'; break;
	case 6:c = '6'; break;
	case 7:c = '7'; break;
	case 8:c = '8'; break;
	case 9:c = '9'; break;
	case 10:c = 'J'; break;
	case 11:c = 'Q'; break;
	case 12:c = 'K'; break;
	default:c = ' '; break;
	}
	return c;
}

int getnum(char a[], int len, int i) {
	if (i > len)
		return 0;
	return char2int(a[len - i]);
}

int main() {
	char str1[110], str2[110];
	int answer[110] = { 0 };
	scanf("%s", str1);
	scanf("%s", str2);
	int len1 = 0, len2 = 0, maxlen, k = 1,num1,num2;

	while (str1[len1] != '\0') {
		len1++;
	}
	while (str2[len2] != '\0') {
		len2++;
	}
	if (len1 > len2)
		maxlen = len1;
	else
		maxlen = len2;
	for (int i = 0; i < maxlen; i++) {
		num1 = getnum(str1, len1, i + 1);
		num2 = getnum(str2, len2, i + 1);
		//ÆæÊýÎ»
		if (k % 2 == 1) {
			answer[maxlen - i - 1] = (num1 + num2) % 13;
		}
		else {
			answer[maxlen - i - 1] = num2 - num1;
			if (answer[maxlen - i - 1] < 0)
				answer[maxlen - i - 1] += 10;
		}
		k++;
	}
	for (int i = 0; i < maxlen; i++) {
		printf("%c", int2char(answer[i]));
	}
	printf("\n");
	return 0;
}