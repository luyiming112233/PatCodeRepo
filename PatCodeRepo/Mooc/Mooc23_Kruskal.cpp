#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct edge {
	int a;
	int b;
	int len;
};

#define maxn 1010

int parent[maxn];

int getParent(int n) {
	int temp = n;
	while (parent[n] != -1) {
		n = parent[n];
	}
	int c;
	while (parent[temp] != -1) {
		c = parent[temp];
		parent[temp] = n;
		temp = c;
	}
	return n;
}

bool cmp(edge a,edge b) {
	if (a.len != b.len) {
		return a.len < b.len;
	}
	else if (a.a != b.a) {
		return a.a < b.a;
	}
	return a.b < b.b;
}

bool judge(edge e) {
	int root1 = getParent(e.a);
	int root2 = getParent(e.b);
	if (root1 != root2)
		return true;
	else
		return false;
}

void edgeunion(edge e) {
	int root1 = getParent(e.a);
	int root2 = getParent(e.b);
	parent[root1] = root2;
}

int main() {
	fill(parent, parent + maxn, -1);
	vector<edge> v;
	int N, M,sum=0,num=0;
	edge temp;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &temp.a, &temp.b, &temp.len);
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), cmp);
	for (int ei = 0; ei < v.size(); ei++) {
		if (judge(v[ei])) {
			sum += v[ei].len;
			edgeunion(v[ei]);
			num++;
			if (num == N - 1)
				break;
		}
	}
	if (num != N - 1) {
		printf("-1");
	}
	else {
		printf("%d", sum);
	}
	return 0;
}