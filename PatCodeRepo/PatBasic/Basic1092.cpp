#include<cstdio>

int main() {
	int N, M,num;
	long long int a[1001] = { 0 },max=0;
	bool first = true;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &num);
			a[j] += num;
		}
	}
	for (int j = 1; j <= N; j++) {
		if (max < a[j])
			max = a[j];
	}
	printf("%lld\n", max);
	
	for (int j = 1; j <= N; j++) {
		if (max == a[j]) {
			if (first) {
				first = false;
				printf("%d", j);
			}
			else {
				printf(" %d", j);
			}
		}
	}
	return 0;
}