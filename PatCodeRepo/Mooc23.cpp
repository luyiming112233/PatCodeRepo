#include<cstdio>
#include<algorithm>
using namespace std;

#define maxn 1010
#define INF 1000000

int mat[maxn][maxn];
int minDis[maxn];
bool connect[maxn] = { false };

int main() {
	fill(mat[0], mat[0] + maxn * maxn, INF);
	fill(minDis, minDis + maxn, INF);
	int N, M,a,b,d,sum=0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &d);
		mat[a][b] = d;
		mat[b][a] = d;
	}
	minDis[1] = 0;
	for (int di = 0; di < N; di++) {
		int index = -1,minD=INF;
		for (int i = 1; i <= N; i++) {
			if (minD > minDis[i] && connect[i]==false) {
				minD = minDis[i];
				index = i;
			}
		}
		if (index == -1)
			break;
		connect[index] = true;
		sum += minDis[index];
		for (int i = 1; i <= N; i++) {
			if (mat[index][i] < minDis[i] && connect[i] == false) {
				minDis[i] = mat[index][i];
			}
		}
	}
	bool flag = true;
	for (int i = 1; i <= N; i++) {
		if (connect[i] == false) {
			flag = false;
			break;
		}
	}
	if (flag == false) {
		printf("-1");
	}
	else {
		printf("%d", sum);
	}
	return 0;
}
