#include<cstdio>

#define maxn 1010

double arry[maxn] = { 0 };

int main() {
	int K, N;
	double a;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %lf", &N, &a);
		arry[N] += a;
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %lf", &N, &a);
		arry[N] += a;
	}
	int size=0;
	for (int i = 0; i < maxn; i++) {
		if (arry[i] != 0)
			size++;
	}
    printf("%d", size);
	for (int i = maxn; i >= 0; i--) 
		if (arry[i] != 0) 
			printf(" %d %.1f", i, arry[i]);
	return 0;
}