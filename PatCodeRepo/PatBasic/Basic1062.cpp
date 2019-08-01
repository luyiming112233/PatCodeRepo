#include<cstdio>

bool judge(int a, int b) {
	int c;
	if (a < b) {
		c = a;
		a = b;
		b = c;
	}
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	if (a != 1)
		return false;
	return true;
}

int main() {
	long long int N1, M1, N2, M2, K,first=0,n1,n2,t;
	scanf("%lld/%lld %lld/%lld %lld", &N1, &M1, &N2, &M2, &K);
	n1 = N1 * M2*K;
	n2 = N2 * M1*K;
	if (n1 > n2) {
		t = n1;
		n1 = n2;
		n2 = t;
	}


	for (int i = 1; i < K; i++) {
		//判断是否有公约数
		if (judge(K,i) || i == 1) {
			t = M1*M2*i;
			if (t > n1 && t < n2) {
				if (first == 0) {
					first++;
					printf("%d/%lld", i, K);
				}
				else {
					printf(" %d/%lld", i, K);
				}
			}
		}
	}
	printf("\n");
	return 0;
}
