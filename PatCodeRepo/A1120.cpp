#include<cstdio>

#define maxn 100

int id[maxn] = { 0 };

void getSum(int num) {
	int sum = 0;
	while (num != 0) {
		sum += (num % 10);
		num /= 10;
	}
	id[sum]++;
}

int main() {
	int N,num,fnum=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		getSum(num);
	}
	for (int i = 0; i < maxn; i++) {
		if (id[i] > 0)
			fnum++;
	}
	printf("%d\n", fnum);
	bool first = true;
	for (int i = 0; i < maxn; i++) {
		if (id[i] > 0) {
			if (first) {
				first = false;
				printf("%d", i);
			}
			else {
				printf(" %d", i);
			}
		}
	}
	return 0;
}