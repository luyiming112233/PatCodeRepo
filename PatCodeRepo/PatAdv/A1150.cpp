#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 210
#define INF 1000000

struct san {
	int dis;
	int type;//1:TS sim;2:TS;3:Not;0:NA
	san() {
		dis = 0;
	}
};

int mat[maxn][maxn];
int connect[maxn];
int N;

san judge() {
	san temp;
	vector<int> path;
	fill(connect, connect + maxn, 0);
	int n, a,b;
	scanf("%d %d", &n,&b);
	bool flag = true;
	for (int i = 1; i < n; i++) {
		a = b;
		scanf("%d", &b);
		connect[b]++;
		if (mat[a][b] == INF)
			flag = false;
		else
			temp.dis += mat[a][b];
	}
	if (flag) {
		bool isTS = true, isSimple = true;
		for (int i = 1; i <= N; i++) {
			if (connect[i] == 0)
				isTS = false;
			if (connect[i] > 1)
				isSimple = false;
		}
		if (!isTS)
			temp.type = 3;
		else {
		    if(isSimple)
				temp.type = 1;
			else
				temp.type = 2;
		}
	}
	else {
		temp.type = 0;
	}
	return temp;
}

int main() {
	fill(mat[0], mat[0] + maxn * maxn, INF);
	int M, K, a, b, d;
	int minDis = INF, index;
	vector<san> v;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &d);
		mat[a][b] = d;
		mat[b][a] = d;
	}
	scanf("%d", &K);
	for (int ki = 0; ki < K; ki++) {
		san temp = judge();
		v.push_back(temp);
		switch(temp.type) {
		case 0:
			printf("Path %d: NA (Not a TS cycle)\n", ki + 1);
			break;
		case 1:
			printf("Path %d: %d (TS simple cycle)\n", ki + 1,temp.dis);
			if (temp.dis < minDis) {
				index = ki + 1;
				minDis = temp.dis;
			}
			break;
		case 2:
			printf("Path %d: %d (TS cycle)\n", ki + 1, temp.dis);
			if (temp.dis < minDis) {
				index = ki + 1;
				minDis = temp.dis;
			}
			break;
		case 3:
			printf("Path %d: %d (Not a TS cycle)\n", ki + 1, temp.dis);
			break;
		}
	}
	printf("Shortest Dist(%d) = %d", index, minDis);
	return 0;
}