#include<cstdio>

int main() {
	int n;
	scanf("%d", &n);
	double a, sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lf", &a);
		sum += a*(i + 1)*(n - i);
	}
	printf("%.2lf\n", sum);
	return 0;
}