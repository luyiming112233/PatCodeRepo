#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N, M,num;
	vector<int> v;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int s = 0, e = N - 1;
	while (s < e) {
		if (v[s] + v[e] == M)
			break;
		if (v[s] + v[e] > M) {
			e--;
		}
		else {
			s++;
		}
	}
	if (s == e) {
		printf("No Solution");
	}
	else {
		printf("%d %d", v[s], v[e]);
	}
	return 0;
}