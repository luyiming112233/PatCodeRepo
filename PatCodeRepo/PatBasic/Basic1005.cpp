#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int a[10000] = { 0 };
	int K, v;
	scanf("%d", &K);
	int *num = new int[K];
	for (int i = 0; i < K; i++) {
		scanf("%d", &num[i]);
		v = num[i];
		while (v != 1) {
			if (v % 2 == 0) {
				v /= 2;
				a[v]++;
			}
			else {
				v = (3 * v + 1) / 2;
				a[v]++;
			}
		}
	}
	sort(num, num + K);
	//Êä³ö½á¹û
	bool first = true;
	for (int i = K - 1; i >= 0; i--) {
		if (a[num[i]] == 0) {
			if (first) {
				printf("%d", num[i]);
				first = false;
			}
			else {
				printf(" %d", num[i]);
			}
		}
	}
	return 0;
}