#include<cstdio>
#include<vector>
#include<set>
using namespace std;

#define maxn 510
#define INF 10000000

struct edge{
	int v, len;
	edge(int vv,int ll) {
		v = vv, len = ll;
	}
};

vector<edge> mat[maxn];
set<int> pre[maxn];
int minD[maxn], hands[maxn], maxH[maxn], pNum[maxn];
int N, M, C1, C2;

bool judge() {
	minD[C1] = 0, maxH[C1] = hands[C1], pNum[C1] = 1;
	for (int ni = 0; ni < N - 1; ni++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < mat[i].size(); j++) {
				int v = mat[i][j].v, len = mat[i][j].len;
				if (minD[v] > minD[i] + len) {
					minD[v] = minD[i] + len;
					maxH[v] = maxH[i] + hands[v];
					pNum[v] = pNum[i];
					pre[v].clear();
					pre[v].insert(i);
				}
				else if (minD[v] == minD[i] + len) {
					if (maxH[v] < maxH[i] + hands[v])
						maxH[v] = maxH[i] + hands[v];
					pNum[v] = 0;
					pre[v].insert(i);
					for (set<int>::iterator it = pre[v].begin(); it != pre[v].end(); it++) 
						pNum[v] += pNum[*it];
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < mat[i].size(); j++) {
			int v = mat[i][j].v, len = mat[i][j].len;
			if (minD[v] > minD[i] + len) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	fill(minD, minD + maxn,INF);
	fill(maxH, maxH + maxn, 0);
	fill(pNum, pNum + maxn, 0);
	int a, b, d;
	scanf("%d %d %d %d", &N, &M, &C1, &C2);
	for (int i = 0; i < N; i++)
		scanf("%d", &hands[i]);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &d);
		mat[a].push_back(edge(b, d));
		mat[b].push_back(edge(a, d));
	}
	bool flag = judge();
	printf("%d %d", pNum[C2], maxH[C2]);
	return 0;
}