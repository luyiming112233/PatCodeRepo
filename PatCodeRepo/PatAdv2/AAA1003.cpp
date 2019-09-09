#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 510
#define INF 10000000

int mat[maxn][maxn];
bool connect[maxn];
int minD[maxn], maxQ[maxn], pNum[maxn],hands[maxn];

int main() {
	fill(mat[0], mat[0] + maxn * maxn, INF);
	fill(connect, connect + maxn, false);
	fill(minD, minD + maxn, INF);
	fill(maxQ, maxQ + maxn, 0);
	fill(pNum, pNum + maxn, 0);
	int N, M, C1, C2,a,b,d;
	scanf("%d %d %d %d", &N, &M, &C1, &C2);
	for (int i = 0; i < N; i++)
		scanf("%d", &hands[i]);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &d);
		mat[a][b] = d;
		mat[b][a] = d;
	}
	maxQ[C1] = hands[C1];
	pNum[C1] = 1;
	minD[C1] = 0;
	for (int ni = 0; ni < N; ni++) {
		int index = -1,DD=INF;
		for (int i = 0; i < N; i++) {
			if (connect[i] == false && DD > minD[i]) {
				DD = minD[i];
				index = i;
			}
		}
		if (index == -1) break;
		connect[index] = true;
		for (int i = 0; i < N; i++) {
			if (connect[i] == false && minD[i] > minD[index] + mat[index][i]) {
				minD[i] = minD[index] + mat[index][i];
				pNum[i] = pNum[index];
				maxQ[i] = maxQ[index] + hands[i];
			}
			else if (connect[i] == false && minD[i] == minD[index] + mat[index][i]) {
				pNum[i] += pNum[index];
				if (maxQ[i] < maxQ[index] + hands[i])
					maxQ[i] = maxQ[index] + hands[i];
			}
		}
	}
	printf("%d %d\n", pNum[C2], maxQ[C2]);
	return 0;
}