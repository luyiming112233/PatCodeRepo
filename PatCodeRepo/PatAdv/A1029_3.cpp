#include<cstdio>
#include<limits.h>
#include<algorithm>
using namespace std;

#define maxn 200010
const long long int mm = INT_MAX;

long int a[maxn] = { 0 };

int main() {
	int N, M,index,s,k,max;
	long long int num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &num);
		if (num > mm) {
			a[i] = INT_MAX;
		}
		else {
			a[i] = (int)num;
		}
	}
	scanf("%d", &M);
	index = (N + M - 1) / 2;
	s = N;
	max = a[N - 1];
	if (N <= index) {
		for (s = N; s <= index; s++) {
			scanf("%lld", &num);
			if (num > mm) {
				a[s] = INT_MAX;
			}
			else {
				a[s] = (int)num;
			}
		}

	}
	
	k = index;
	for (int i = s-N; i < M; i++) {
		scanf("%lld", &num);
		if (num > mm) {
			num = INT_MAX;
		}
		if (num >= a[k]) {
			continue;
		}
		else {
			a[k] = num;
			k--;
		}
	}
	if (k < 0)
		k = index;
	//sort(a, a + index + 1);
	printf("%d", a[index]);
}