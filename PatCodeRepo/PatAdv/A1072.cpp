#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define maxn 1020
#define slen 10
#define INF 10000000

struct answer {
	int id;
	double min;
	double avg;
	double max;
};

int mat[maxn][maxn];
int dis[maxn];
bool connect[maxn];
int N, M, K, D,A;
vector<answer> v;

int trans(char a[slen]) {
	int num = 0,i=0,id=0;
	if (a[0] == 'G') {
		i = 1;
		num = N;
	}
	for (; i < slen; i++) {
		if (a[i] == '\0')
			break;
		id = id * 10 + a[i] - '0';
	}
	return id + num-1;
}

void calAnswer(int id) {
	double sum = 0, min = D;
	answer tanswer;
	for (int i = 0; i < N; i++) {
		sum += dis[i];
		if (dis[i] < min)
			min = dis[i];
	}
	tanswer.id = id;
	tanswer.min = min;
	tanswer.avg = sum / N;
	v.push_back(tanswer);
}

bool cmp(answer a, answer b) {
	if (a.min != b.min) {
		return a.min > b.min;
	}
	else if (a.avg != b.avg) {
		return a.avg < b.avg;
	}
	else {
		return a.id < b.id;
	}
}

int main() {
	scanf("%d%d%d%d", &N, &M, &K, &D);
	A = N + M;
	char c1[slen], c2[slen];
	int d,ic1,ic2,start,minD,minIndex;
	bool isAnswer;
	fill(mat[0], mat[0] + maxn * maxn, INF);
	for (int i = 0; i < K; i++) {
		scanf("%s %s %d", c1, c2, &d);
		ic1 = trans(c1);
		ic2 = trans(c2);
		mat[ic1][ic2] = d;
		mat[ic2][ic1] = d;
	}
	for (int i = 0; i < M; i++) {
		//遍历所有可能的站点
		start = N + i;
		fill(connect, connect + maxn, false);
		fill(dis, dis + maxn, INF);
		dis[start] = 0;
		isAnswer = true;
		for (int j = 0; j < A; j++) {
		    //找到最近的点
			minD = INF;
			minIndex = -1;
			for (int ti = 0; ti < A; ti++) {
				//更近且为达到
				if (dis[ti] < minD && connect[ti]==false) {
					minD = dis[ti];
					minIndex = ti;
				}
			}
			//跳出可能,无法达到要求
			if (minIndex<N && minD>D) {
				isAnswer = false;
				break;
			}
			if (minIndex == -1)
				break;
			//更新最短距离
			connect[minIndex] = true;
			for (int ti = 0; ti < A; ti++) {
				if (mat[minIndex][ti]!=INF && connect[ti] == false && dis[minIndex] + mat[minIndex][ti] < dis[ti]) {
					dis[ti] = dis[minIndex] + mat[minIndex][ti];
				}
			}
		}
		//保证所有的house都能达到
		if (isAnswer) {
			for (int ti = 0; ti < N; ti++) {
				if (dis[ti] > D) {
					isAnswer = false;
					break;
				}
			}
		}
		//判断是否是可行解
		if (isAnswer) {
			calAnswer(start);
		}
	}
	if (v.size() == 0) {
		printf("No Solution");
	}
	else {
		sort(v.begin(), v.end(), cmp);
		printf("G%d\n", v[0].id - N+1);
		printf("%.1f %.1f", v[0].min, v[0].avg);
	}
	return 0;
}