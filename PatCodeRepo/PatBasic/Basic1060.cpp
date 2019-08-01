#include<cstdio>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n;
	scanf("%d", &n);
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n, cmp);
	int E = 0;
	while (E < n) {
		if (E+1 < a[E]) {
			E++;
		}else{
			break;
		}
		
	}
	printf("%d\n", E);
}