#include<cstdio>

#define maxn 1010

int heap[maxn] = { 0 };

void swap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

void insert(int value,int N) {
	heap[N] = value;
	int i = N, j = N / 2;
	while (j > 0) {
		if (heap[i] < heap[j]) {
			swap(heap[i], heap[j]);
			i = j;
			j = i / 2;
		}
		else {
			break;
		}
	}
}

void query() {
	int start;
	scanf("%d", &start);
	bool flag = true;
	while (start >= 1) {
		if (flag) {
			flag = false;
			printf("%d", heap[start]);
		}else
			printf(" %d", heap[start]);
		start /= 2;
	}
	printf("\n");
}

int main() {
	int N, M, num;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &num);
		insert(num, i);
	}
	for (int i = 0; i < M; i++) 
		query();
	return 0;
}