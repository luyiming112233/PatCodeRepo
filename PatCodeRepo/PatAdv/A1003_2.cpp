#include<cstdio>
#include<algorithm>
using namespace std;

#define INF 1000000000
#define maxN 500

int dis[maxN];
int dmat[maxN][maxN];
int hand[maxN];
int maxhand[maxN];
int num[maxN];

int main() {
	int N, M, C1, C2,ti,tj,tv;
	scanf("%d%d%d%d", &N, &M, &C1, &C2);
	bool city[maxN] = {false};
	
	fill(dis, dis + maxN, INF);
	fill(dmat[0], dmat[0] + maxN * maxN, INF);
	fill(maxhand, maxhand + maxN, 0);
	fill(num, num + maxN, 0);
	for (int i = 0; i < N; i++) {
		scanf("%d", &hand[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &ti, &tj, &tv);
		dmat[ti][tj] = tv;
		dmat[tj][ti] = tv;
	}

	maxhand[C1] = hand[C1];
	num[C1] = 1;
	dis[C1] = 0;

	int cid, min_dis;
	for (int i = 0; i < N; i++) {
		min_dis = INF;
		cid = -1;
		for (int j = 0; j < N; j++) {
			if (city[j] == false && dis[j] < min_dis) {
				min_dis = dis[j];
				cid = j;
			}
		}
		if (cid == -1)
			break;
		city[cid] = true;

		for (int j = 0; j < N; j++) {
			if (city[j] == false && dmat[cid][j] != INF && (dmat[cid][j] + dis[cid] < dis[j])) {
				dis[j] = dmat[cid][j] + dis[cid];
				num[j] = num[cid];
				maxhand[j] = maxhand[cid] + hand[j];
			}
			else if (city[j] == false && dmat[cid][j] != INF && (dmat[cid][j] + dis[cid] == dis[j])) {
				num[j] += num[cid];
				if(maxhand[cid] + hand[j]>maxhand[j])
					maxhand[j] = maxhand[cid] + hand[j];
			}
		}
	}
	printf("%d %d", num[C2], maxhand[C2]);
	return 0;
}