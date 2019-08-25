#include<cstdio>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	a += b;
	if (a < 0) {
		printf("-");
		a = -a;
	}
	if (a / 1000000 > 0) {
		printf("%d,", a / 1000000);
		printf("%03d,", a / 1000%1000);
		printf("%03d", a % 1000);
	}
	else if (a / 1000 > 0) {
		printf("%d,", a / 1000);
		printf("%03d", a % 1000);
	}
	else {
		printf("%d", a);
	}
	return 0;
}