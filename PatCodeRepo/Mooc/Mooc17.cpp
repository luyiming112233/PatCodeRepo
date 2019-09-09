#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

#define maxn 1010

vector<int> mat[maxn];
bool connect[maxn];
int N, M;

int main() {
	scanf("%d %d", &N, &M);
	int a, b,level,pid,num;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		mat[a].push_back(b);
		mat[b].push_back(a);
	}
	for (int ni = 1; ni <= N; ni++) {
		fill(connect, connect + maxn, false);
		connect[ni] = true;
		queue<int> q;
		q.push(ni);
		q.push(-1);
		level = 0;
		num = 1;
		while (!q.empty()) {
			pid = q.front();
			q.pop();
			if (pid == -1) {
				level++;
				if (!q.empty()) {
					q.push(-1);
				}
				if (level == 6)
					break;
			}
			else {
				for (int i = 0; i < mat[pid].size(); i++) {
					if (connect[mat[pid][i]] == false) {
						q.push(mat[pid][i]);
						connect[mat[pid][i]] = true;
						num++;
					}
				}
			}
		}
		printf("%d: %.2f%%\n", ni, 100.0*num / N);
	}
	return 0;
}