#include<cstdio>
#include<vector>
using namespace std;

#define maxn 100010

vector<int> v[maxn];

int maxD = 0,num=0;

void DFS(int root,int d) {
	d++;
	if (v[root].size() == 0) {
		if (d > maxD) {
			maxD = d;
			num = 1;
		}
		else if (d==maxD) {
			num++;
		}
	}
	else {
		for (int i = 0; i < v[root].size(); i++) {
			DFS(v[root][i], d);
		}
	}
}

int main() {
	int N,root,su;
	double P, R;
	scanf("%d %lf %lf", &N, &P, &R);
	R = R / 100 + 1;
	for (int i = 0; i < N; i++) {
		scanf("%d", &su);
		if (su == -1) {
			root = i;
		}
		else {
			v[su].push_back(i);
		}
	}
	DFS(root, 0);
	for (int i = 0; i < maxD-1; i++) {
		P *= R;
	}
	printf("%.2f %d", P, num);
}