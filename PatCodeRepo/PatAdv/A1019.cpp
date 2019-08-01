#include<cstdio>
#include<vector>
using namespace std;

int main() {
	long long int N, b,temp,tt=0;
	vector<long long> v;
	bool first = true;
	scanf("%lld%lld", &N, &b);
	temp = N;
	while (temp != 0) {
		v.push_back(temp%b);
		tt = tt * b + (temp%b);
		temp /= b;
	}
	if (N == tt) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		if (first) {
			printf("%lld", v[i]);
			first = false;
		}else
			printf(" %lld", v[i]);
	}
	return 0;
}