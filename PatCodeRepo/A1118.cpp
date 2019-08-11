#include<cstdio>
#include<algorithm>
using namespace std;

#define maxn 10010

int parent[maxn];
bool birds[maxn] = { false };

int getType(int n) {
	int temp = n;
	while (parent[n] > -1) {
		n = parent[n];
	}
	while (parent[temp] > -1) {
		int c = parent[temp];
		parent[temp] = n;
		temp = c;
	}
	return n;
}

void punion(int a, int b) {
	if (parent[a] > parent[b]) {
		parent[b] += parent[a];
		parent[a] = b;
	}
	else {
		parent[a] += parent[b];
		parent[b] = a;
	}
}

int main() {
	fill(parent, parent + maxn, -1);
	int N,K,Q,a,b,roota,rootb,bnum=0,tnum=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &K);
		scanf("%d", &a);
		birds[a] = true;
		for (int j = 1; j < K; j++) {
			scanf("%d", &b);
			birds[b] = true;
			roota = getType(a);
			rootb = getType(b);
			punion(roota, rootb);
		}
	}
	for (int i = 0; i < maxn; i++) {
		if (birds[i]) {
			bnum++;
			if (parent[i] < 0)
				tnum++;
		}
	}
	printf("%d %d\n", tnum, bnum);
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d %d", &a, &b);
		roota = getType(a);
		rootb = getType(b);
		if (roota == rootb)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}