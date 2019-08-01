#include<cstdio>
using namespace std;

#define maxn 100010

int a[maxn] = {0};

int main() {
	int N, M, sum = 0, dis, start, end, len, temp;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &dis);
		sum += dis;
		a[i] = sum;
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &start, &end);
		start--;
		end--;
		if (start > end) {
			temp = start;
			start = end;
			end = temp;
		}
		len = a[end] - a[start];
		if (len > sum - len)
			len = sum - len;
		printf("%d\n", len);
	}
	return 0;
}