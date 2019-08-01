#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<long long> v;
	int N, M;
	long long int num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &num);
		v.push_back(num);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%lld", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	printf("%lld", v[(N + M-1) / 2]);
	return 0;
}
