#include<cstdio>
#include<cmath>

int main() {
	int n, a, b;
	double max = 0, v;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &a, &b);
		v = a * a + b * b;
		if (v > max)
			max = v;
	}
	max = sqrt(max);
	printf("%.2lf\n", max);
	return 0;
}