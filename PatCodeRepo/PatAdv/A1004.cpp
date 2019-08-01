#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

#define nmax 100

int main() {
	int N, M,id,k,cid;
	int mat[nmax][nmax], nochild[nmax];
	bool haveChild[nmax] = { false };
	queue<int> q;
	scanf("%d", &N);
	if (N == 0)
		return 0;
	scanf("%d", &M);
	fill(mat[0], mat[0] + nmax * nmax,-1);
	fill(nochild, nochild + nmax, -1);
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &id,&k);
		if (k == 0)
			continue;
		haveChild[id] = true;
		for (int j = 0; j < k; j++) {
			scanf("%d", &cid);
			mat[id][cid] = 1;
		}
	}
	mat[1][0] = 0;
	nochild[0] = 0;
	q.push(1);
	while (!q.empty()) {
		cid = q.front();
		q.pop();
		for (int i = 1; i < nmax; i++) {
			if (mat[cid][i] == 1) {
				q.push(i);
				mat[i][0] = mat[cid][0] + 1;
			}
		}
	}
	for (int i = 1; i < nmax; i++) {
		if (mat[i][0] != -1 && nochild[mat[i][0]]==-1)
			nochild[mat[i][0]] = 0;
		if (mat[i][0] != -1 && haveChild[i]==false) {
			nochild[mat[i][0]]++;
		}
	}

	bool first = true;
	for (int i = 0; i < nmax; i++) {
		if (nochild[i] != -1) {
			if (first) {
				printf("%d", nochild[i]);
				first = false;
			}
			else
				printf(" %d", nochild[i]);
		}
	}
	return 0;
}