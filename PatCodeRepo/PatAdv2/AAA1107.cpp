#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

#define maxn 1010

int parent[maxn];
vector<int> peo[maxn];

int getParent(int root) {
	int temp = root;
	while (parent[temp] > 0)
		temp = parent[temp];
	while (parent[root]>0) {
		int c = parent[root];
		parent[root] = temp;
		root = c;
	}
	return root;
}

void Union(int a,int b) {
	int pa = getParent(a), pb = getParent(b);
	if (pa == pb) return;
	parent[pa] = pb;
}

int main() {
	fill(parent, parent + maxn, -1);
	int N, K, a, b,par;
	map<int, int> m;
	map<int, int>::iterator it;
	vector<int> answer;
	scanf("%d", &N);
	for (int ni = 1; ni <= N; ni++) {
		scanf("%d: %d", &K,&b);
		peo[ni].push_back(b);
		for (int i = 1; i < K; i++) {
			a = b;
			scanf("%d", &b);
			peo[ni].push_back(b);
			Union(a, b);
		}
	}
	for (int i = 1; i <= N; i++) {
		par = getParent(peo[i][0]);
		it = m.find(par);
		if (it == m.end()) m[par] = 0;
		m[par]++;
	}
	for (it = m.begin(); it != m.end(); it++)
		answer.push_back(it->second);
	sort(answer.begin(), answer.end());
	reverse(answer.begin(), answer.end());
	printf("%d\n", answer.size());
	for (int i = 0; i < answer.size(); i++) {
		if (i == 0) printf("%d", answer[i]);
		else printf(" %d", answer[i]);
	}
	return 0;
}