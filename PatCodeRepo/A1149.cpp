#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 100010

bool pro[maxn];
vector<int> v[maxn];

int main() {
	int N, M,K,a,b;
	bool flag;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int mi = 0; mi < M; mi++) {
		scanf("%d", &K);
		fill(pro, pro + maxn, false);
		flag = true;
		for (int i = 0; i < K; i++) {
			scanf("%d", &a);
			if (pro[a])
				flag = false;
			for (int j = 0; j < v[a].size(); j++) {
				pro[v[a][j]] = true;
			}
		}
		if (flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}