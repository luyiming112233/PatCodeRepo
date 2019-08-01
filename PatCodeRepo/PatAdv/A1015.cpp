#include<cstdio>
#include<algorithm>
using namespace std;

#define maxn 1000010

bool prime[maxn];

int reverenum(int num, int r) {
	int rnum = 0;
	while (num != 0) {
		rnum = rnum * r + (num%r);
		num /= r;
	}
	return rnum;
}

int main() {
	fill(prime, prime + maxn, true);
	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i*i <= maxn; i++) {
		for (int j = 2 * i; j < maxn; j += i)
			prime[j] = false;
	}
	int N, D;
	while (~scanf("%d", &N)) {
		if (N<=0)
			break;
		scanf("%d", &D);
		if (prime[N] && prime[reverenum(N,D)]) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}