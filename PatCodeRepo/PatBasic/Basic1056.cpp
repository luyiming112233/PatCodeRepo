#include<cstdio>

int main() {
	int n,num,sum=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		sum += num;
	}
	sum *= ((n - 1) * 11);
	printf("%d\n", sum);
	return 0;
}