#include<cstdio>
#include<queue>
using namespace std;

#define maxn 510

int degree[maxn] = { 0 };
int mat[maxn][maxn] = { 0 };
bool connect[maxn] = { false };

int main() {
	int N, M, a, b,temp,num;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		degree[a]++;
		degree[b]++;
		mat[a][b] = 1;
		mat[b][a] = 1;
	}
	int odd = 0;
	for (int i = 1; i <= N; i++) {
		if (degree[i] % 2 == 1)
			odd++;
		if (i == 1) {
			printf("%d", degree[i]);
		}
		else {
			printf(" %d", degree[i]);
		}
	}
	printf("\n");
	queue<int> q;
	q.push(1);
	connect[1] = true;
	num = 1;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (connect[i] == false && mat[temp][i]) {
				q.push(i);
				num++;
				connect[i] = true;
			}
		}
	}
	if (odd == 0 && num==N) {
		printf("Eulerian");
	}
	else if (odd == 2 && num == N) {
		printf("Semi-Eulerian");
	}
	else {
		printf("Non-Eulerian");
	}
	return 0;
}