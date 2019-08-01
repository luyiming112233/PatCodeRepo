#include<cstdio>
#include<math.h>
#include<map>
using namespace std;

int a[1010][1010];

int main() {
	int M, N, TOL,num,x,y,temp;
	int *a[1010];
	for (int i = 0; i < 1010; i++) {
		a[i] = new int[1010];
	}
	map<int, int> m;
	map<int, int>::iterator it;
	for (int i = 0; i < 1010; i++)
		for (int j = 0; j < 1010; j++)
			a[i][j] = -1;
	int off[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
	scanf("%d%d%d", &M, &N, &TOL);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &a[i][j]);
			it = m.find(a[i][j]);
			if (it == m.end()) {
				m[a[i][j]] = 1;
			}
			else {
				it->second++;
			}
		}
	}

	num = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (m[a[i][j]] != 1)
				continue;
			for (temp = 0; temp < 8; temp++) {
				if (a[i + off[temp][0]][j + off[temp][1]] == -1)
		        	continue;
				if (abs(a[i + off[temp][0]][j + off[temp][1]] - a[i][j]) <= TOL)
					break;
			}
			if (temp == 8) {
				//printf("test:(%d, %d): %d\n", i, j, a[i][j]);
				temp = 0;
				num++;
				if (num == 1) {
					x = j;
					y = i;
				}
				else {
					//通过修改i和j的值跳出循环
					i = N + 1;
					j = M + 1;
				}
			}
		}
	}
	if (num == 0)
		printf("Not Exist\n");
	else if (num == 1)
		printf("(%d, %d): %d\n", x, y, a[y][x]);
	else {
		printf("Not Unique\n");
	}
	return 0;
}