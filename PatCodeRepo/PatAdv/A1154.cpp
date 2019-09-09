#include<cstdio>
#include<unordered_set>
#include<vector>
using namespace std;

struct edge {
	int a, b;
	edge(int aa, int bb) {
		a = aa, b = bb;
	}
};

vector<edge> v;
int N;

int judge() {
	unordered_set<int> s;
	vector<int> color;
	int c, a, b;
	for (int i = 0; i < N; i++) {
		scanf("%d", &c);
		s.insert(c);
		color.push_back(c);
	}
	for (int i = 0; i < v.size(); i++) {
		a = v[i].a, b = v[i].b;
		if (color[a] == color[b]) return -1;
	}
	return s.size();
}

int main() {
	int M, a, b, K, num;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		v.push_back(edge(a, b));
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		num = judge();
		if (num == -1) printf("No\n");
		else printf("%d-coloring\n", num);
	}
	return 0;
}