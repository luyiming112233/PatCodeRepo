#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define maxn 110

void BFS(int N,int M) {
	vector<int> v[maxn],answer;
	int isRoot[maxn] = { 0 };
	int id, K, kid,root;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &id, &K);
		for (int j = 0; j < K; j++) {
			scanf("%d", &kid);
			isRoot[kid] = 1;
			v[id].push_back(kid);
		}
	}
	for (root = 1; root <= N; root++) 
		if (isRoot[root] == 0)
			break;
	queue<int> q;
	int qid, num=0;
	q.push(root);
	q.push(-1);
	while (!q.empty()) {
		qid = q.front();
		q.pop();
		if (qid == -1) {
			answer.push_back(num);
			num = 0;
			if (!q.empty())
				q.push(-1);
		}
		else {
			if (v[qid].size() == 0)
				num++;
			else {
				for (int i = 0; i < v[qid].size(); i++)
					q.push(v[qid][i]);
			}
		}
	}
	for (int i = 0; i < answer.size(); i++) {
		if (i == 0) printf("%d",answer[i]);
		else printf(" %d", answer[i]);
	}
	printf("\n");
}

int main() {
	int N, M;
	while (scanf("%d", &N)!=EOF) {
		scanf("%d", &M);
		BFS(N, M);
	}
	return 0;
}