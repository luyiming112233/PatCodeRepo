#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> v;
	int N,num;
	int sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	if (N % 2 == 1) {
		if (v[N / 2] > 0)
			sum += v[N / 2];
		else
			sum -= v[N / 2];
	}
	for (int i = 0; i < N / 2; i++) {
		sum -= v[i];
		sum += v[N - 1 - i];
	}
	if (N % 2 == 1)
		printf("1 ");
	else
		printf("0 ");
	printf("%d", sum);
	return 0;
}