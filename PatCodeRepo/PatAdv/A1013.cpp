#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

#define maxn 1010

int mat[maxn][maxn];

int main() {	
	fill(mat[0], mat[0] + maxn * maxn, 0);
	int N, M, K,a,b,e,num,temp;
	queue<int> q;
	bool connect[maxn];
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		mat[a][b] = 1;
		mat[b][a] = 1;
	}
	for (int i = 0; i < K; i++) {
		scanf("%d", &e);
		fill(connect, connect + maxn, false);
		connect[e] = true;
		num = -1;
		for (int j = 1; j <= N; j++) {
			if (connect[j] == false) {
				q.push(j);
				connect[j] = true;
				num++;
			}
			while (!q.empty()) {
				temp = q.front();
				q.pop();
				for (int k = 1; k <= N; k++) {
					if (mat[temp][k] == 1 && connect[k]==false && temp != k && k != j) {
						q.push(k);
						connect[k] = true;
					}
				}
			}
		}
		printf("%d\n", num);
	}
	return 0;
}