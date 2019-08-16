#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

#define maxn 110
#define INF 100000

int time[maxn] = { 0 };
int indegree[maxn] = { 0 };
int mat[maxn][maxn];

int main() {
	fill(mat[0], mat[0] + maxn * maxn, INF);
	int N, M,s,e,l,qid;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &s, &e, &l);
		mat[s][e] = l;
		indegree[e]++;
	}
	queue<int> q;
	for (int i = 0; i < N; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		qid = q.front();
		q.pop();
		for (int i = 0; i < N; i++) {
			if (mat[qid][i] != INF) {
				if (mat[qid][i] + time[qid] > time[i])
					time[i] = mat[qid][i] + time[qid];
				indegree[i]--;
				if (indegree[i] == 0)
					q.push(i);
			}
		}
	}
	bool flag = true;
	int maxT = 0;
	for (int i = 0; i < N; i++) {
		if (indegree[i] != 0) {
			flag = false;
			break;
		}
		if (time[i] > maxT)
			maxT = time[i];
	}
	if (flag == false) {
		printf("Impossible");
	}
	else {
		printf("%d", maxT);
	}
	return 0;
}