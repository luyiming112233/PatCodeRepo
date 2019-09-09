#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<string.h>
using namespace std;

#define maxn 210
#define INF 10000000
#define slen 5

int mat[maxn][maxn], happy[maxn], maxH[maxn], pNum[maxn],minD[maxn];
bool connect[maxn] = { false };
map<string, int> Cnum;
map<int, string> City;
vector<int> pre[maxn];
vector<int> path, temp;
int HH = 0, avgH = 0;


void update() {
	int hsum = 0;
	for (int i = 0; i < temp.size(); i++) 
		hsum += happy[temp[i]];
	if (hsum > HH) {
		HH = hsum;
		path = temp;
	}else if(hsum == HH && temp.size()<path.size())
		path = temp;
	avgH = HH / (path.size()-1);
}

void DFS(int root) {
	temp.push_back(root);
	if (root == 0) update();
	else {
		for (int i = 0; i < pre[root].size(); i++)
			DFS(pre[root][i]);
	}
	temp.pop_back();
}

int main() {
	fill(mat[0], mat[0] + maxn * maxn, INF);
	fill(happy, happy + maxn, 0);
	fill(maxH, maxH + maxn, 0);
	fill(minD, minD + maxn, INF);
	fill(pNum, pNum + maxn, 0);
	char sa[slen], sb[slen],start[slen];
	int N, M, h, d,Cs=0,Ce;
	scanf("%d %d %s", &N, &M, start);
	Cnum[start] = 0, City[0] = start;
	for (int i = 1; i < N; i++) {
		scanf("\n%s %d", sa, &happy[i]);
		Cnum[sa] = i, City[i] = sa;
	}
	for (int i = 0; i < M; i++) {
		scanf("\n%s %s %d", sa, sb, &d);
		int va = Cnum[sa], vb = Cnum[sb];
		mat[va][vb] = d, mat[vb][va] = d;
	}
	Ce = Cnum["ROM"];
	maxH[Cs] = 0, minD[Cs] = 0, pNum[Cs] = 1;
	for (int ni = 0; ni < N; ni++) {
		int index = -1, DD = INF;
		for (int i = 0; i < N; i++) {
			if (connect[i] == false && minD[i] < DD) {
				DD = minD[i];
				index = i;
			}
		}
		if (index == -1) break;
		connect[index] = true;
		for (int i = 0; i < N; i++) {
			if (connect[i] == false && mat[i][index] != INF && minD[i] > minD[index] + mat[i][index]) {
				minD[i] = minD[index] + mat[i][index];
				pre[i].clear();
				pre[i].push_back(index);
				maxH[i] = maxH[index] + happy[i];
				pNum[i] = pNum[index];
			}
			else if (connect[i] == false && mat[i][index] != INF && minD[i] == minD[index] + mat[i][index]) {
				if (maxH[i] < maxH[index] + happy[i]) {
					maxH[i] = maxH[index] + happy[i];
				}
				pre[i].push_back(index);
				pNum[i] += pNum[index];
			}
		}
	}
	DFS(Ce);
	printf("%d %d %d %d\n", pNum[Ce], minD[Ce], maxH[Ce],avgH);
	reverse(path.begin(), path.end());
	for (int i = 0; i < path.size(); i++) {
		if (i == 0) printf("%s", City[path[i]].c_str());
		else printf("->%s", City[path[i]].c_str());
	}
	return 0;
}