#include<cstdio>
#include<algorithm>
using namespace std;

#define maxn 110
#define INF 1000000

int dis[maxn][maxn];
int maxDis[maxn];

int main() {
	int N, M,a,b,d,min=INF,index;
	fill(dis[0], dis[0] + maxn * maxn, INF);
	fill(maxDis, maxDis + maxn, -1);
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		dis[i][i] = 0;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &d);
		dis[a][b] = d;
		dis[b][a] = d;
	}
	for (int k = 1; k <= N; k++) 
		for(int i=1;i<=N;i++)
			for (int j = 1; j <= N; j++) {
				if (dis[i][j] > dis[i][k] + dis[k][j])
					dis[i][j] = dis[i][k] + dis[k][j];
			}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dis[i][j] > maxDis[i])
				maxDis[i] = dis[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		if (min > maxDis[i]) {
			index = i;
			min = maxDis[i];
		}
	}
	if (min == INF)
		printf("0");
	else
    	printf("%d %d", index, min);
	return 0;
}