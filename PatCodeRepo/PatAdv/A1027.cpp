#include<cstdio>

char tran(int n) {
	if (n < 10)
		return n + '0';
	n -= 10;
	return n + 'A';
}

int main() {
	int a, b, c;
	char str[8];
	scanf("%d%d%d", &a, &b, &c);
	str[0] = '#';
	str[1] = tran(a / 13);
	str[2] = tran(a % 13);
	str[3] = tran(b / 13);
	str[4] = tran(b % 13);
	str[5] = tran(c / 13);
	str[6] = tran(c % 13);
	str[7] = '\0';
	printf("%s", str);
	return 0;
}