#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 210

int mat[maxn][maxn];
int connect[maxn];

int main() {
	int Nv, Ne,a,b;
	fill(mat[0], mat[0] + maxn * maxn, 0);
	scanf("%d %d", &Nv, &Ne);
	for (int i = 1; i <= Nv; i++) {
		mat[i][i] = 1;
	}
	for (int i = 0; i < Ne; i++) {
		scanf("%d %d", &a, &b);
		mat[a][b] = 1;
		mat[b][a] = 1;
	}
	int M, K,vet;
	scanf("%d", &M);
	for (int mi = 0; mi < M; mi++) {
		scanf("%d", &K);
		vector<int> v;
		bool isMax = true,isCli=true;
		fill(connect, connect + maxn, 0);
		for (int i = 0; i < K; i++) {
			scanf("%d", &vet);
			v.push_back(vet);
			for (int j = 1; j <= Nv; j++) {
				if (mat[vet][j] == 1)
					connect[j]++;
			}
		}
		for (int i = 0; i < v.size(); i++) {
			if (connect[v[i]] != K) {
				isCli = false;
			}
			else {
				connect[v[i]] = 0;
			}
		}
		if (isCli) {
			for (int i = 1; i <= Nv; i++) {
				if (connect[i] == K) {
					isMax = false;
					break;
				}
			}
			if (isMax) {
				printf("Yes\n");
			}
			else {
				printf("Not Maximal\n");
			}
		}
		else{
			printf("Not a Clique\n");
		}
	}
	return 0;
}