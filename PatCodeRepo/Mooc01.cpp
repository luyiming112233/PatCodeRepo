#include<cstdio>

#define maxn 100010

int a[maxn] = { 0 };

int main() {
	int n, s = 0,sum=0,max=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	while (s < n) {
		sum += a[s];
		if (sum > max) {
			max = sum;
		}
		if (sum < 0)
			sum = 0;
		s++;
	}
	printf("%d", max);
	return 0;
}