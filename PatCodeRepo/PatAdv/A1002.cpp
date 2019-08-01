#include<cstdio>

int main() {
	int K, N,num=0;
	double sum[1001] = { 0 },a;
	int status[1001] = { 0 };
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %lf", &N, &a);
		if (status[N] == 0) {
			status[N]++;
		}
		sum[N] += a;
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %lf", &N, &a);
		if (status[N] == 0) {
			status[N]++;
		}
		sum[N] += a;
	}
	for (int i = 1000; i >= 0; i--) {
		if (sum[i] > 0.05 || sum[i] < -0.05) {
			num++;
		}
		else
			sum[i] = 0;
	}

	printf("%d", num);
	for (int i = 1000; i >= 0; i--) {
		if (sum[i] > 0.05 || sum[i] < -0.05)
    		printf(" %d %.1lf", i, sum[i]);
	}
	return 0;
}