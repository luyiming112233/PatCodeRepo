#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<string.h>

using namespace std;

#define maxn 210
#define slen 5
#define INF 10000000

vector<vector <int> >path;
vector<int> tpath;
vector<int> cpath[maxn];
map<string, int> cid;
string cname[maxn];
int mat[maxn][maxn];
int happy[maxn];
bool comecity[maxn];
int minDis[maxn];
int maxHappy[maxn];
int N, K;

void deep(int c) {
	tpath.push_back(c);
	if (c == -1) {
		path.push_back(tpath);
	}
	else {
		for (int i = 0; i < cpath[c].size(); i++) {
			deep(cpath[c][i]);
		}
	}
	tpath.pop_back();

}

void printPath(vector<int> v) {
	bool first = true;
	for (int i = v.size() - 1; i--; i >= 0) {
		if (first) {
			first = false;
			printf("%s", cname[v[i]].c_str());
		}
		else {
			printf("->%s", cname[v[i]].c_str());
		}
	}
}

int main() {
	fill(mat[0], mat[0] + maxn * maxn, INF);
	fill(happy, happy + maxn, 0);
	fill(comecity, comecity + maxn, false);
	fill(minDis, minDis + maxn, INF);
	fill(maxHappy, maxHappy + maxn, 0);
	scanf("%d %d", &N, &K);
	char c1[slen], c2[slen];
	scanf("%s", c1);
	int ha,cost,cstart,cminD;
	cid[c1] = 0;
	cname[0] = c1;
	for (int i = 1; i < N; i++) {
		scanf("%s %d", c1, &ha);
		cid[c1] = i;
		happy[i] = ha;
		cname[i] = c1;
	}
	for (int i = 0; i < K; i++) {
		scanf("%s %s %d", c1, c2, &cost);
		mat[cid[c1]][cid[c2]] = cost;
		mat[cid[c2]][cid[c1]] = cost;
	}

	minDis[0] = 0;
	cpath[0].push_back(-1);
	for (int qi = 0; qi < N; qi++) {
		cstart = -1,cminD=INF;
		for (int i = 0; i < N; i++) {
			if (comecity[i] == false && cminD > minDis[i]) {
				cstart = i;
				cminD = minDis[i];
			}
		}
		comecity[cstart] = true;
		for (int i = 0; i < N; i++) {
			if (comecity[i] == false && mat[cstart][i] != INF && minDis[cstart] + mat[cstart][i] < minDis[i]) {
				minDis[i] = minDis[cstart] + mat[cstart][i];
				maxHappy[i] = maxHappy[cstart] + happy[i];
				cpath[i].clear();
				cpath[i].push_back(cstart);
			}
			else if (comecity[i] == false && mat[cstart][i] != INF && minDis[cstart] + mat[cstart][i] == minDis[i]) {
				if (maxHappy[i] < maxHappy[cstart] + happy[i]) {
					maxHappy[i] = maxHappy[cstart] + happy[i];
				}
				cpath[i].push_back(cstart);

			}
		}
	}
	int Rome = cid["ROM"],minSize=INF,Id=0,maxH=-1;
	deep(Rome);
	for (int i = 0; i < path.size(); i++) {
		int hhh = 0;
		for (int j = 0; j < path[i].size();j++) {
			hhh += happy[path[i][j]];
		}
		if (hhh > maxH) {
			maxH = hhh;
			Id = i;
			minSize = path[i].size();
		}
		else if (hhh == maxH) {
			if (minSize > path[i].size()) {
				Id = i;
				minSize = path[i].size();
			}
		}
	}
	printf("%d %d %d %d\n", path.size(), minDis[Rome], maxHappy[Rome], maxHappy[Rome]/(minSize-2));
	printPath(path[Id]);
	return 0;
}