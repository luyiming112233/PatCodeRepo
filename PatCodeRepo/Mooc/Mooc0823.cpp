#include<cstdio>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

#define maxn 110
#define INF 100000

struct edge {
	int s, e, l;
	int lt, et;
};

int Ve[maxn] = { 0 };
int Vl[maxn];
int indegree[maxn] = { 0 };
int mat[maxn][maxn];

bool cmp(edge a, edge b) {
	return a.s > b.s;
}

int main() {
	fill(mat[0], mat[0] + maxn * maxn, INF);
	int N, M, s, e, l, qid;
	vector<edge> v;
	edge temp;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &s, &e, &l);
		mat[s][e] = l;
		indegree[e]++;
		temp.s = s;
		temp.e = e;
		temp.l = l;
		v.push_back(temp);
	}
	queue<int> q;
	stack<int> topOrder;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			topOrder.push(i);
		}
	}
	while (!q.empty()) {
		qid = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (mat[qid][i] != INF) {
				if (mat[qid][i] + Ve[qid] > Ve[i])
					Ve[i] = mat[qid][i] + Ve[qid];
				indegree[i]--;
				if (indegree[i] == 0) {
					q.push(i);
					topOrder.push(i);
				}
			}
		}
	}
	bool flag = true;
	int maxT = 0;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] != 0) {
			flag = false;
			break;
		}
		if (Ve[i] > maxT)
			maxT = Ve[i];
	}
	if (flag == false) {
		printf("0");
		return 0;
	}
	fill(Vl, Vl + maxn, maxT);
	while (!topOrder.empty()) {
		qid = topOrder.top();
		topOrder.pop();
		for (int i = 1; i <= N; i++) {
			if (mat[qid][i] != INF) {
				if (Vl[qid] > Vl[i] - mat[qid][i]) {
					Vl[qid] = Vl[i] - mat[qid][i];
				}
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		//活动最早时间等于起点的最早时间
		v[i].et = Ve[v[i].s];
		//活动最晚时间等于终点最晚时间减去活动时间
		v[i].lt = Vl[v[i].e] - v[i].l;
	}
	sort(v.begin(), v.end(), cmp);
	printf("%d\n", maxT);
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i].et == v[i].lt) {
			printf("%d->%d\n", v[i].s, v[i].e);
		}
	}
	return 0;
}