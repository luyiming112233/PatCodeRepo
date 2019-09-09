#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

#define maxn 10010

vector<int> v[maxn];

int main() {
	set<int> s;
	int N, M,a,b,K,vertex,Nv;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(i);
		v[b].push_back(i);
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &Nv);
		s.clear();
		for (int j = 0; j < Nv; j++) {
			scanf("%d", &vertex);
			for (int z = 0; z < v[vertex].size(); z++) {
				s.insert(v[vertex][z]);
			}
		}
		if (s.size() == M) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}