#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int n, p, *a, min, max, k;
	scanf("%d%d", &n, &p);
	a = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	min = 0, max = 0, k = 0;
	while (max < n) {
		if ((long long)a[max] <= (long long)a[min] * (long long)p) {
			if (max - min + 1 > k)
				k = max - min + 1;
			max++;
		}
		else {
			min++;
		}
	}
	printf("%d\n", k);
	return 0;
}