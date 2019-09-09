#include<cstdio>
#include<algorithm>
using namespace std;

#define maxn 510
#define INF 1000000

int mdis[maxn][maxn];
int mcost[maxn][maxn];
bool connect[maxn];
int minDis[maxn];
int minCost[maxn];

int main() {
	fill(mdis[0], mdis[0] + maxn * maxn, INF);
	fill(mcost[0], mcost[0] + maxn * maxn, INF);
	fill(minCost, minCost + maxn, INF);
	fill(minDis, minDis + maxn, INF);
	fill(connect, connect + maxn, false);
	int N, M, S, D,a,b,d,c;
	scanf("%d %d %d %d", &N, &M, &S, &D);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d", &a, &b, &d, &c);
		mdis[a][b] = d;
		mdis[b][a] = d;
		mcost[a][b] = c;
		mcost[b][a] = c;
	}
	minDis[S] = 0;
	minCost[S] = 0;
	for (int ti = 0; ti < N; ti++) {
		int index = -1;
		int minD = INF;
		for (int i = 0; i < N; i++) {
			if (connect[i] == false && minDis[i] < minD) {
			    minD = minDis[i];
				index = i;
			}
		}
		if (index == -1)
			break;
		connect[index] = true;
		for (int i = 0; i < N; i++) {
			if (connect[i] == false && minDis[i] > minDis[index] + mdis[index][i]) {
				minDis[i] = minDis[index] + mdis[index][i];
				minCost[i] = minCost[index] + mcost[index][i];
			}
			else if (connect[i] == false && minDis[i] == minDis[index] + mdis[index][i] && minCost[i] > minCost[index] + mcost[index][i]) {
				minCost[i] = minCost[index] + mcost[index][i];
			}
		}
	}
	printf("%d %d\n", minDis[D], minCost[D]);
	return 0;
}
