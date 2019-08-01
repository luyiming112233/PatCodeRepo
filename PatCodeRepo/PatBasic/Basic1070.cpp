#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int *a = new int[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	sort(a, a + N);
	int sum = a[0];
	for (int i = 1; i < N; i++) {
		sum = (sum + a[i]) / 2;
	}
	printf("%d\n", sum);
	return 0;
}