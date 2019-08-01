#include<cstdio>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

#define maxn 510
#define INF 1000000000

int N, M, S, D, ta, tb, td, tc;
int dis[maxn][maxn], cost[maxn][maxn], path[maxn], mind[maxn], mincost[maxn];
bool city[maxn];

int main() {
	fill(dis[0], dis[0] + maxn * maxn,INF);
	fill(cost[0], cost[0] + maxn * maxn, INF);
	fill(path, path + maxn, -1);
	fill(mind, mind + maxn, INF);
	fill(mincost, mincost + maxn, INF);
	fill(city, city + maxn, false);
	scanf("%d%d%d%d", &N, &M, &S, &D);
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d%d", &ta, &tb, &td, &tc);
		dis[ta][tb] = td;
		dis[tb][ta] = td;
		cost[ta][tb] = tc;
		cost[tb][ta] = tc;
	}
	mind[S] = 0;
	mincost[S] = 0;
	int zmin,zcity;
	while (true) {
		zcity = -1;
		zmin = INF;
		for (int i = 0; i < N; i++) {
			if (city[i] == false && zmin > mind[i]) {
				zmin = mind[i];
				zcity = i;
			}
		}
		if (zcity == -1)
			break;
		city[zcity] = true;
		for (int i = 0; i < N; i++) {
			if (city[i] == true)
				continue;
			if (mind[zcity] + dis[zcity][i] < mind[i]) {
				mind[i] = mind[zcity] + dis[zcity][i];
				path[i] = zcity;
				mincost[i] = mincost[zcity] + cost[zcity][i];
			
			}
			else if (mind[zcity] + dis[zcity][i] == mind[i]) {
				if (mincost[i] > mincost[zcity] + cost[zcity][i]) {
					mincost[i] = mincost[zcity] + cost[zcity][i];
					path[i] = zcity;
				}
			}
		}
	}

	vector<int> answer;
	int end = D;
	while (end != -1) {
		answer.push_back(end);
		end = path[end];
	}
	for (int i = answer.size() - 1; i >= 0; i--) {
		printf("%d ", answer[i]);
	}
	printf("%d %d", mind[D], mincost[D]);
	return 0;
}