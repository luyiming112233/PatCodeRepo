#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

#define maxn 20

int mat[maxn][maxn];
bool connect[maxn];
int N, E;

void DFS(int root) {
	connect[root] = true;
	printf(" %d", root);
	for (int i = 0; i < N; i++) {
		if (mat[root][i] == 1 && connect[i] == false) {
			DFS(i);
		}
	}
}

int main() {
	fill(mat[0], mat[0] + maxn * maxn, 0);
	fill(connect, connect + maxn, false);
	int a,b,temp;
	scanf("%d %d", &N, &E);
	for (int i = 0; i < E; i++) {
		scanf("%d %d", &a, &b);
		mat[a][b] = 1;
		mat[b][a] = 1;
	}
	for (int i = 0; i < N; i++) {
		if (connect[i])
			continue;
		printf("{");
		DFS(i);
		printf(" }\n");
	}
	fill(connect, connect + maxn, false);
	queue<int> q;
	for (int i = 0; i < N; i++) {
		if (connect[i])
			continue;
		q.push(i);
		connect[i] = true;
		printf("{");
		while (!q.empty()) {
			temp = q.front();
			q.pop();
			printf(" %d", temp);
			for (int j = 0; j < N; j++) {
				if (mat[temp][j] == 1 && connect[j]==false) {
					connect[j] = true;
					q.push(j);
				}
			}
		}
		printf(" }\n");
	}
	return 0;
}