#include<cstdio>

#define maxn 100010

int a[maxn],ink[maxn],startfind;

void swap(int i, int j) {
	//数组值交换
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
	//下标交换
	t = ink[a[i]];
	ink[a[i]] = ink[a[j]];
	ink[a[j]] = t;
}

int main() {
	int N,step=0,d;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		ink[a[i]] = i;
	}
	startfind = 0;
	while (true) {
		if (ink[0] == 0) {
			for (d = startfind; (d+startfind)%N < N; d++) {
				if (a[d] != d) {
					startfind = d % N;
					break;
				}
			}
			if (d == N)
				break;
			else {
				step++;
				swap(0, d);
			}
		}
		else {
			step++;
			//交换0和0对应下标位置的数
			//ink[0]表示0的下标，ink[ink[0]]表示0对应下标的数的下标
			swap(ink[0], ink[ink[0]]);
		}
	}
	printf("%d", step);
}