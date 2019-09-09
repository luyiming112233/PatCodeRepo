#include<cstdio>

int main() {
	int N;
	scanf("%d", &N);
	double sum = 0,num;
	for (int i = 1; i <= N; i++) {
		scanf("%lf", &num);
		sum += (1.0*i*(N - i + 1)*num);
	}
	printf("%.2f", sum);
}