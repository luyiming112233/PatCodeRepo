#include<cstdio>
#include<vector>
using namespace std;

#define maxn 110

struct node {
	int id,degree,time;
	node() {
		degree = 0, time;
	}
}nodes[maxn];

struct edge {
	int v, len;
	edge(int vv,int ll) {
		v = vv, len = ll;
	}
};

vector<edge> mat[maxn];

int main(){
	int N, M, a, b, d,events=0,maxT=0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &d);
		nodes[b].degree++;
		mat[a].push_back(edge(b, d));
	}
	for (int ni = 0; ni < N; ni++) {
		int index = -1;
		for (int i = 0; i < N; i++) {
			if (nodes[i].degree == 0) {
				index = i;
				nodes[i].degree = -1;
				events++;
				break;
			}
		}
		if (index == -1) break;
		for (int i = 0; i < mat[index].size(); i++) {
			int v = mat[index][i].v, len = mat[index][i].len;
			nodes[v].degree--;
			if (nodes[index].time + len > nodes[v].time) nodes[v].time = nodes[index].time + len;
			if (maxT < nodes[v].time) maxT = nodes[v].time;
		}
	}
	if (events != N) printf("Impossible\n");
	else printf("%d\n",maxT);
	return 0;
}
