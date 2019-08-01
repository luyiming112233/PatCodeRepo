#include<cstdio>

int main() {
	int M,N,K,temp,wei;
	scanf("%d", &M);
	while (M--){
		scanf("%d", &K);
		wei = 10;
		while (wei < K)
			wei *= 10;
		for (N = 1; N < 10; N++) {
			temp = K * K*N;
			if (temp%wei == K)
				break;
		}
		if (N != 10) {
			printf("%d %d\n", N, temp);
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}