#include<cstdio>

int main() {
	int a[101] = { 0 }, n, m, grade;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &grade);
		a[grade]++;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &grade);
		if (i != 0)
			printf(" %d", a[grade]);
		else
			printf("%d", a[grade]);
	}
	printf("\n");
	return 0;
}