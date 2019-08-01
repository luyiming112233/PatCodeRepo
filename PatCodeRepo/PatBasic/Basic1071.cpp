#include<cstdio>

int main() {
	int T, K, n1, b, t, n2;
	scanf("%d%d", &T, &K);
	for (int i = 0; i < K; i++) {
		scanf("%d%d%d%d", &n1, &b, &t, &n2);
		if (t > T) {
			printf("Not enough tokens.  Total = %d.\n", T);
			continue;
		}
		//¶Än1>n2
		else if (b == 0) {
			if (n1 > n2) {
				T += t;
				printf("Win %d!  Total = %d.\n", t, T);
			}
			else {
				T -= t;
				printf("Lose %d.  Total = %d.\n", t, T);
			}
		}
		//¶Än1<n2
		else if (b == 1) {
			if (n1 < n2) {
				T += t;
				printf("Win %d!  Total = %d.\n", t, T);
			}
			else {
				T -= t;
				printf("Lose %d.  Total = %d.\n", t, T);
			}
		}
		if (T == 0) {
			printf("Game Over.\n");
			break;
		}
			
	}
	return 0;
}