#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define maxn 510
#define INF 10000000

int Cm, N, Sp, M, bikes[maxn] = { 0 }, mat[maxn][maxn],
a, b, d, dis[maxn], cid, mindis, half_Cm;

vector<int> pre[maxn],temppath,answer;
int minneed = INF,back_num=INF;

void DFS(int v) {
	if (v == 0) {
		int bikenum = 0,minbike=INF,need;
		for (int i = temppath.size()-1; i >=0; i--) {
			bikenum += (bikes[temppath[i]] - half_Cm);
			if (bikenum < minbike)
				minbike = bikenum;
		}
		if (minbike >= 0) {
			need = 0;
		}else{
			need = -minbike;
		}
		if (minneed > need) {
			minneed = need;
			back_num = bikenum + need;
			answer.assign(temppath.begin(),temppath.end());
		}
		else if (minneed == need && back_num>bikenum+need) {
			back_num = bikenum + need;
			answer.assign(temppath.begin(), temppath.end());
		}
	}
	else {
		temppath.push_back(v);
		for (int i = 0; i < pre[v].size(); i++) {
			DFS(pre[v][i]);
		}
		temppath.pop_back();
	}
}

int main() {
	bool station[maxn] = { false };
	vector<int> v;
	fill(dis, dis + maxn, INF);
	fill(mat[0], mat[0] + maxn * maxn, INF);
	scanf("%d%d%d%d", &Cm, &N, &Sp, &M);
	half_Cm = Cm / 2;
	for (int i = 1; i <= N; i++)
		scanf("%d", &bikes[i]);
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &a, &b,&d);
		mat[a][b] = d;
		mat[b][a] = d;
	}
	//初始化
	dis[0] = 0;
	for (int i = 0; i <= N; i++) {
		cid = -1;
		mindis = INF;
		for (int j = 0; j <= N; j++) {
			if (station[j] == false && mindis > station[j]) {
				cid = j;
				mindis = station[j];
			}
		}
		if (cid == -1)
			break;
		station[cid] = true;
		for (int j = 0; j <= N; j++) {
			if (station[j] == false && mat[cid][j]!=INF && dis[j] > dis[cid] + mat[cid][j]) {
				dis[j] = dis[cid] + mat[cid][j]; //更新最短距离
				pre[j].clear();  //更新路径
				pre[j].push_back(cid);
			}
			else if (station[j] == false && mat[cid][j] != INF && dis[j] == dis[cid] + mat[cid][j]) {
				pre[j].push_back(cid);  //更新路径	
			}
		}
	}
	DFS(Sp);
	printf("%d ", minneed);
	//输出路径
	printf("0");
	for (int i = answer.size() - 1; i >= 0; i--) {
		printf("->%d", answer[i]);
	}
	printf(" %d", back_num);
	return 0;
}