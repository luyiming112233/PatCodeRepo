#include<cstdio>
#include<vector>
using namespace std;

int main() {
	int N, num, max = -10000000, start = 0, ms, me, tsum = 0;
	vector<int> v;
	scanf("%d", &N);
	bool flag = false;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	for (int i = 0; i < N; i++) {
		tsum += v[i];
		if (v[i] == 0 && 0>=max) {
			max = 0;
			ms = i;
			me = i;
			flag = true;
		}
		if (tsum >= 0) {
			flag = true;
		}
		if (tsum < 0) {
			tsum = 0;
			start = i + 1;
		}
		if (tsum > max) {
			max = tsum;
			ms = start;
			me = i;
		}
	}
	if (flag == false) {
		printf("0 %d %d", v[0], v[N-1]);
	}
	else {
		printf("%d %d %d", max, v[ms], v[me]);
	}
	return 0;
}