#include<cstdio>

int main() {
	int N;
	scanf("%d", &N);
	int num,t,*b = new int[N];
	for (int i = 0; i < N; i++) {
		b[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		if (i + 1 > num) {
			t = i + 1 - num;
		}
		else {
			t = num - i - 1;
		}
		b[t]++;
	}
	for (int i = N-1; i >=0 ; i--) {
		if (b[i] > 1) {
			printf("%d %d\n", i, b[i]);
		}
	}
	return 0;
}