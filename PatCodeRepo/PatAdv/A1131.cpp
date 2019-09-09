#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 10010
#define INF 100000000

struct edge {
	int v, line;
	edge(int vv, int ll) {
		v = vv, line = ll;
	}
};

vector<edge> mat[maxn], path, answer;
bool connect[maxn];
int minL = INF, minD = INF;

void judge(int D) {
	int Lnum = 0, line = -1;
	for (int i = 0; i < path.size(); i++) {
		if (path[i].line != line) {
			line = path[i].line;
			Lnum++;
		}
	}
	if (D < minD) {
		minD = D;
		answer = path;
		minL = Lnum;
	}
	else if (D == minD && Lnum < minL) {
		answer = path;
		minL = Lnum;
	}
}

void DFS(int root, int dest, int D) {
	connect[root] = true;
	D++;
	if (root == dest) judge(D);
	else {
		for (int i = 0; i < mat[root].size(); i++) {
			int p = mat[root][i].v;
			if (connect[p] == false) {
				path.push_back(mat[root][i]);
				DFS(p, dest, D);
				path.pop_back();
			}
		}
	}
	D--;
	connect[root] = false;
}

int main() {
	int N, M, a, b, line, K;
	scanf("%d", &N);
	for (int ni = 1; ni <= N; ni++) {
		scanf("%d", &M);
		scanf("%d", &b);
		for (int i = 1; i < M; i++) {
			a = b;
			scanf("%d", &b);
			mat[a].push_back(edge(b, ni));
			mat[b].push_back(edge(a, ni));
		}
	}
	scanf("%d", &K);
	for (int ki = 0; ki < K; ki++) {
		minL = INF, minD = INF;
		fill(connect, connect + maxn, false);
		path.clear(), answer.clear();
		scanf("%d %d", &a, &b);
		DFS(a, b, -1);
		printf("%d\n", minD);
		int start = a, next = answer[0].v, line = answer[0].line;
		for (int i = 0; i < answer.size(); i++) {
			if (line == answer[i].line) {
				next = answer[i].v;
			}
			else {
				printf("Take Line#%d from %04d to %04d.\n", line, start, next);
				line = answer[i].line;
				start = next;
				next = answer[i].v;
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", line, start, next);
	}
	return 0;
}