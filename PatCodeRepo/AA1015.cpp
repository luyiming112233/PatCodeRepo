#include<cstdio>
#include<math.h>

#define maxn 100010

int prime[maxn] = { 0 };

void buildPrime() {
	prime[1] = 1;
	for (int i = 2; i < sqrt(maxn) + 1; i++) {
		if (prime[i] == 0) {
			for (int j = 2 * i; j < maxn; j += i)
				prime[j] = 1;
		}
	}
}

bool judge(int N, int D) {
	if (prime[N] == 1) return false;
	int num = 0;
	while (N != 0) {
		num = num * D + N % D;
		N /= D;
	}
	if (prime[num] == 1) return false;
	return true;
}

int main() {
	int N, D;
	buildPrime();
	while (true) {
		scanf("%d", &N);
		if (N < 0) break;
		scanf("%d", &D);
		if (judge(N, D)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
