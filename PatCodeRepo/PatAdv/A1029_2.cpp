#include<cstdio>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

const long long int maxnum = INT_MAX;
vector<int> v;

void del() {
	vector<int>::iterator it,imax;
	imax = v.begin();
	for (it = v.begin(); it != v.end(); it++) {
		if (*it > *imax)
			imax = it;
	}
	v.erase(imax);
}

int main() {
	int N, M,index;
    long long num;
	vector<int>::iterator it;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &num);
		if (num >= maxnum)
			v.push_back(INT_MAX);
		else
			v.push_back((int)num);
	}
	sort(v.begin(), v.end());
	scanf("%d", &M);
	index = (M + N + 1) / 2;
	while (v.size() > index) {
		del();
	}
	for (int i = 0; i < M; i++) {
		scanf("%lld", &num);
		if (num >= maxnum)
			v.push_back(INT_MAX);
		else
			v.push_back((int)num);
		while (v.size() > index)
			del();
	}
	int max = -100000000000000;
	for (it = v.begin(); it != v.end(); it++) {
		if (*it > max)
			max = *it;
	}
	printf("%d", max);
}