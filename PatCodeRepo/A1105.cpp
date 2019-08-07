#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define maxn 1010

bool cmp(int a, int b) {
	return a > b;
}

int mat[maxn][maxn] = { 0 };

int main() {
	int N,num,m,n,mi,ni,flag,right,left,up,down;
	scanf("%d", &N);
	for (int i = 1; i*i <= N; i++) {
		if (N%i == 0) {
			n = i;
			m = N / i;
		}
	}
	vector<int> v;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end(), cmp);
	mi = 1, ni = 1,flag=1;
	left = 1;
	right = n;
	up = 1;
	down = m;
	for (int i = 0; i < v.size(); i++) {
		mat[mi][ni] = v[i];
		switch (flag) {
		case 1:
			if (ni == right) {
				mi++;
				up++;
				flag = 2;
			}
			else {
				ni++;
			}
			break;
		case 2:
			if (mi == down) {
				ni--;
				right--;
				flag = 3;
			}
			else {
				mi++;
			}
			break;
		case 3:
			if (ni == left) {
				mi--;
				down--;
				flag = 4;
			}
			else {
				ni--;
			}
			break;
		case 4:
			if (mi == up) {
				ni++;
				left++;
				flag = 1;
			}
			else {
				mi--;
			}
			break;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (j == 1) {
				printf("%d", mat[i][j]);
			}
			else {
				printf(" %d", mat[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}