#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define maxn 210

int mat[maxn][maxn] = {0};
int come[maxn];
int N, M,K;

bool judge() {
	int n,first,num;
	fill(come, come + maxn, 0);
	vector<int> v;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	first = v[0];
	//come[first]++;
	for (int i = 0; i < n - 1; i++) {
		if (mat[v[i]][v[i + 1]] == 1) {
			come[v[i + 1]]++;
		}
		else {
			return false;
		}
	}
	//首尾不相等
	if (v[n - 1] != first)
		return false;
	for (int i = 1; i <= N; i++) {
		if (come[i] != 1)
			return false;
	}
	return true;
}

int main() {
	int a,b;
	scanf("%d %d",&N,&M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		mat[a][b] = 1;
		mat[b][a] = 1;
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		if (judge()) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}