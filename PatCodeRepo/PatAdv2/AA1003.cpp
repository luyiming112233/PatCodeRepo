#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 510
#define INF 100000

int mat[maxn][maxn];
int minDis[maxn];
int pathNum[maxn];
int team[maxn];
int maxTeam[maxn];
bool connect[maxn];

int main() {
	fill(mat[0], mat[0] + maxn * maxn, INF);
	fill(minDis, minDis + maxn, INF);
	fill(pathNum, pathNum + maxn, 0);
	fill(team, team + maxn, 0);
	fill(maxTeam, maxTeam + maxn, 0);
	fill(connect, connect + maxn, false);
	int N, M, C1, C2, a, b, d;
	scanf("%d %d %d %d", &N, &M, &C1, &C2);
	for (int i = 0; i < N; i++) 
		scanf("%d", &team[i]);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &d);
		mat[a][b] = d;
		mat[b][a] = d;
	}
	int index, TminDis;
	maxTeam[C1] = team[C1];
	minDis[C1] = 0;
	pathNum[C1] = 1;
	for (int ni = 0; ni < N; ni++) {
		index = -1, TminDis = INF;
		for (int i = 0; i < N; i++) {
			if (minDis[i] < TminDis && connect[i] == false) {
				TminDis = minDis[i];
				index = i;
			}
		}
		if (index == -1) break;
		connect[index] = true;
		for (int i = 0; i < N; i++) {
			if (mat[i][index] != INF && minDis[i] > minDis[index] + mat[i][index] && connect[i] == false) {
				minDis[i] = minDis[index] + mat[i][index];
				maxTeam[i] = maxTeam[index] + team[i];
				pathNum[i] = pathNum[index];
			}
			else if (mat[i][index] != INF && minDis[i] == minDis[index] + mat[i][index] && connect[i] == false) {
				if (maxTeam[i] < maxTeam[index] + team[i]) 
					maxTeam[i] = maxTeam[index] + team[i];
				pathNum[i] += pathNum[index];
			}
		}
	}
	printf("%d %d", pathNum[C2], maxTeam[C2]);
	return 0;
}