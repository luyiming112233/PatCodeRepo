#include<cstdio>

int main() {
	int a[100] = { 0,1 }, num, l, k, i, j;
	char c;
	scanf("%d %c", &num, &c);
	for (i = 2; i < 100; i++) {
		a[i] = a[i - 1] + 2 * (2 * i - 1);
	}
	for (i = 1; i < 100; i++) {
		if (a[i] > num) {
			l = num - a[i - 1];
			k = i - 1;
			break;
		}
	}
	for (i = 0; i < k - 1; i++) {
		//��ӡ�ո�
		for (j = 0; j < i; j++)
			printf(" ");
		//��ӡ����
		for (j = 0; j < (k - 1 - i) * 2 + 1; j++)
			printf("%c", c);
		printf("\n");
	}
	//��ӡ�м�ո�
	for (j = 0; j < k - 1; j++)
		printf(" ");
	printf("%c\n", c);

	for (i = 0; i < k - 1; i++) {
		//��ӡ�ո�
		for (j = 0; j < k - 2 - i; j++)
			printf(" ");
		//��ӡ����
		for (j = 0; j < i * 2 + 3; j++)
			printf("%c", c);
		printf("\n");
	}
	printf("%d\n", l);
	return 0;
}