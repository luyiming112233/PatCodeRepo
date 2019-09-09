#include<cstdio>
#include<vector>
#include<set>
using namespace std;

#define maxn 510
#define INF 1000000

struct node {
	int v, e;
	node(int vv,int ee) {
		v = vv, e = ee;
	}
};

set<int> pre[maxn];
vector<node> mat[maxn];
int num[maxn],minD[maxn];
int team[maxn], W[maxn];

bool Ben(int N,int C1) {
	fill(num, num + maxn, 0);
	fill(W, W + maxn, 0);
	fill(minD, minD + maxn, INF);
	minD[C1] = 0, W[C1] = team[C1], num[C1] = 1;
	for (int ni = 0; ni < N; ni++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < mat[i].size(); j++) {
				int v = mat[i][j].v, d = mat[i][j].e;
				if (minD[v] > minD[i] + d) {
					minD[v] = minD[i] + d;
					W[v] = W[i] + team[v];
					num[v] = num[i];
					pre[v].clear();
					pre[v].insert(i);
				}
				else if (minD[v] == minD[i] + d) {
					if (W[i] + team[v] > W[v]) W[v] = W[i] + team[v];
					num[v] = 0;
					pre[v].insert(i);
					set<int>::iterator it;
					for (it = pre[v].begin(); it != pre[v].end(); it++)
						num[v] += num[*it];
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < mat[i].size(); j++) {
			int v = mat[i][j].v, d = mat[i][j].e;
			if (minD[v] > minD[i] + d) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int N, M, C1, C2,a,b,d;
	scanf("%d %d %d %d", &N, &M, &C1, &C2);
	for (int i = 0; i < N; i++)
		scanf("%d", &team[i]);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &d);
		mat[a].push_back(node(b, d));
		mat[b].push_back(node(a, d));
	}
	Ben(N, C1);
	printf("%d %d", num[C2], W[C2]);
	return 0;
}
