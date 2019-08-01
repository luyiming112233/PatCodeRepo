#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 100010

struct node {
	int index;
	int num;
	int next;
}nodes[maxn];

int main() {
	int first, N, K,in;
	vector<node> v;
	scanf("%d %d %d", &first, &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &in);
		nodes[in].index = in;
		scanf("%d %d", &nodes[in].num, &nodes[in].next);
	}
	while (first != -1) {
		v.push_back(nodes[first]);
		first = nodes[first].next;
	}
	for (int i = 0; i+K <= v.size(); i += K) {
		reverse(v.begin() + i, v.begin() + i + K);
	}
	for (int i = 0; i < v.size() - 1; i++) {
		printf("%05d %d %05d\n", v[i].index, v[i].num, v[i + 1].index);
	}
	if(v.size()!=0)
    	printf("%05d %d -1\n", v[v.size() - 1].index, v[v.size() - 1].num);
	return 0;
}