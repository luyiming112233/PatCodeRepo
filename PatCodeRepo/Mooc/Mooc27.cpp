#include<cstdio>

#define maxn 55

int a[maxn] = { 0 };

int main() {
	int N,age;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &age);
		a[age]++;
	}
	for (int i = 0; i < maxn; i++) 
		if (a[i] != 0) 
			printf("%d:%d\n", i, a[i]);
	return 0;
}
