#include<cstdio>
#include<algorithm>
#include<queue>
#include<math.h>
using namespace std;

#define maxn 110

struct point {
	int x, y;
}points[maxn];

int mat[maxn][maxn];
bool connect[maxn];
int N, D, DD;
double SS,minDis=10000000;
vector<int> path[maxn],answer,tanswer;

bool isConnect(point a, point b) {
	int dis = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
	if (dis <= DD) {
		return true;
	}
	return false;
}

bool isStart(point a) {
	double dis = 1.0*a.x*a.x + 1.0*a.y*a.y;
	if (dis <= SS) {
		return true;
	}
	else {
		return false;
	}
}

bool judge(point &a) {
	if (50 - a.x <= D || a.x + 50 <= D || 50 - a.y <= D || a.y + 50 <= D)
		return true;
	return false;
}

double getDis(point a) {
	double ld = sqrt(a.x*a.x + a.y*a.y);
	return ld - 7.5;
}

void DFS(int root) {
	if (root == 0) {
		double tdis = getDis(points[tanswer[tanswer.size() - 1]]);
		if (tdis < minDis) {
			answer = tanswer;
			minDis = tdis;
		}
		return;
	}
	tanswer.push_back(root);
	for (int i = 0; i < path[root].size(); i++) {
		DFS(path[root][i]);
	}
	tanswer.pop_back();
}

int main() {
	int temp;
	bool flag = false;
	queue<int> q;
	fill(mat[0], mat[0] + maxn * maxn, 0);
	fill(connect, connect + maxn, false);
	scanf("%d %d", &N, &D);
	DD = D * D;
	SS = (7.5 + D)*(7.5 + D);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &points[i].x, &points[i].y);
		if (judge(points[i])) {
			mat[N+1][i] = 1;
		}
		if (isStart(points[i])) {
			mat[0][i] = 1;
		}
	}
	if (judge(points[0])) {
		mat[N + 1][0] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (isConnect(points[i], points[j])) {
				mat[i][j] = 1;
				mat[j][i] = 1;
			}
		}
	}
	q.push(0);
	q.push(-1);
	connect[0] = false;
	int step = 0;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (temp == -1) {
			if (!q.empty()) {
				q.push(-1);
				step++;
			}
			else
				break;
			if (flag)
				break;
		}
		else {
			if (mat[N + 1][temp]) {
				flag = true;
				path[N + 1].push_back(temp);
			}
			for (int i = 1; i <= N; i++) {
				if (mat[temp][i] == 1 && connect[i] == false) {
					q.push(i);
					connect[i] = true;
					path[i].push_back(temp);
				}
			}
		}
	}
	if (flag) {
		DFS(N + 1);
		printf("%d\n", answer.size());
		for (int i = answer.size() - 1; i > 0; i--) {
			printf("%d %d\n", points[answer[i]].x, points[answer[i]].y);
		}
	}
	else {
		printf("0");
	}
	return 0;
}