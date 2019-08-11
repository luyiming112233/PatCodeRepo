#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

#define maxn 110

struct point {
	int x, y;
	bool flag;
	point() {
		flag = false;
	}
}points[maxn];

int mat[maxn][maxn];
bool connect[maxn];
int N, D,DD;
double SS;

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

void judge(point &a) {
	if (50 - a.x <= D || a.x + 50 <= D || 50 - a.y <= D || a.y + 50 <= D)
		a.flag = true;
}

int main() {
	int temp;
	bool flag = false;
	queue<int> q;
	fill(mat[0], mat[0] + maxn * maxn, 0);
	scanf("%d %d", &N, &D);
	DD = D * D;
	SS = (7.5 + D)*(7.5 + D);
	for (int i = 0; i <N; i++) {
		scanf("%d %d", &points[i].x, &points[i].y);
		judge(points[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j=i + 1; j < N; j++) {
			if (isConnect(points[i], points[j])) {
				mat[i][j] = 1;
				mat[j][i] = 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (isStart(points[i])) {
			fill(connect, connect + maxn, false);
			connect[i] = true;
			q.push(i);
			while (!q.empty()) {
				temp = q.front();
				q.pop();
				for (int j = 0; j < N; j++) {
					if (mat[temp][j] == 1 && connect[j] == false) {
						connect[j] = true;
						q.push(j);
					}
				}
			}
			for (int k = 0; k < N; k++) {
			    if(connect[k]&&points[k].flag)
					flag = true;
			}
			if (flag) {
				break;
			}
		}
	}
	if (flag) {
		printf("Yes");
	}
	else {
		printf("No");
	}
	return 0;
}