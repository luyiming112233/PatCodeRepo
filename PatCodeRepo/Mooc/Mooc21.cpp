#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 1010
#define INF 1000000

int mat[maxn][maxn];
int minD[maxn];
bool connect[maxn] = { false };

int main() {
	int N, M,a,b,d;
	fill(mat[0], mat[0] + maxn * maxn, INF);
	fill(minD, minD + maxn, INF);
	scanf("%d %d",&N,&M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &d);
		mat[a][b] = d, mat[b][a] = d;
	}
	minD[1] = 0;
	int sum = 0;
	for (int ni = 0; ni < N; ni++) {
		int index = -1, DD = INF;
		for (int i = 1; i <= N; i++) {
			if (connect[i] == false && minD[i] < DD) {
				index = i, DD = minD[i];
			}
		}
		if (index == -1) break;
		connect[index] = true;
		sum += DD;
		for (int i = 1; i <= N; i++) {
			if (connect[i] == false && mat[index][i] != INF && minD[i] > mat[index][i])
				minD[i] =  mat[index][i];
		}
	}
	bool flag = true;
	for (int i = 1; i <= N; i++) {
		if (connect[i] == false) {
			flag = false;
			break;
		}
	}
	if (!flag) printf("-1");
	else printf("%d", sum);
	return 0;
}