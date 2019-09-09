#include<cstdio>
#include<unordered_set>
using namespace std;

#define maxn 55

unordered_set<int> s[maxn];

void sim(int a,int b) {
	int alen = s[a].size(), blen = s[b].size();
	int num = 0;
	if (alen < blen) {
		for (unordered_set<int>::iterator it = s[a].begin(); it != s[a].end(); it++)
			if (s[b].find(*it) != s[b].end())
				num++;
	}
	else {
		for (unordered_set<int>::iterator it = s[b].begin(); it != s[b].end(); it++)
			if (s[a].find(*it) != s[a].end())
				num++;
	}
	double answer = 100.0*num / (alen + blen - num);
	printf("%.1f%%\n", answer);
}

int main() {
	int N, M, num, K, a, b;
	scanf("%d", &N);
	for (int ni = 1; ni <= N; ni++) {
		scanf("%d", &M);
		for (int i = 0; i < M; i++) {
			scanf("%d", &num);
			s[ni].insert(num);
		}
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &a, &b);
		sim(a, b);
	}
	return 0;
}