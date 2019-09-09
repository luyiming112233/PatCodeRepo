#include<cstdio>
#include<vector>
using namespace std;

#define maxn 100010

vector<int> mat[maxn];
int N, W[maxn] = {0};
double P, r, sum = 0;

void DFS(int root, double price) {
	if (mat[root].size() == 0) {
		sum += (1.0*W[root] * price);
	}
	else {
		for (int i = 0; i < mat[root].size(); i++) {
			DFS(mat[root][i], price*r);
		}
	}
}

int main() {
	scanf("%d %lf %lf", &N, &P, &r);
	r = (r / 100) + 1;
	int K,num;
	for (int ni = 0; ni < N; ni++) {
		scanf("%d", &K);
		if (K == 0) {
			scanf("%d", &W[ni]);
		}
		else {
			for (int i = 0; i < K; i++) {
				scanf("%d", &num);
				mat[ni].push_back(num);
			}
		}
	}
	DFS(0, P);
	printf("%.1f", sum);
	return 0;
}