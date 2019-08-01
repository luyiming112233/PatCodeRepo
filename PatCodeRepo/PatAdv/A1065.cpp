#include<cstdio>

#define LL long long int

int main() {
	int N;
	LL a, b, c,temp;
	scanf("%d", &N);
	bool large;
	for (int i = 1; i <= N; i++) {
		scanf("%lld%lld%lld", &a, &b, &c);
		temp = a + b;
		if (a > 0 && b > 0 && temp < 0)
			large = true;
		else if (a < 0 && b < 0 && temp>=0)
			large = false;
		else {
			large = (temp > c);
		}
		printf("Case #%d: ", i);
		if (large)
			printf("true\n");
		else
			printf("false\n");
	}
	return 0;
}