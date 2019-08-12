#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define maxn 100010

struct node {
	int address;
	int data;
	int next;
}nodes[maxn];

int main() {
	vector<node> v;
	int start, N, K,add;
	scanf("%d %d %d", &start, &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &add);
		nodes[add].address = add;
		scanf("%d %d", &nodes[add].data, &nodes[add].next);
	}
	while (start != -1) {
		v.push_back(nodes[start]);
		start = nodes[start].next;
	}
	for (int b = 0; b + K <= v.size(); b += K) {
		reverse(v.begin() + b, v.begin() + b + K);
	}
	if (v.size() == 1) {
		printf("%05d %d -1", v[0].address, v[0].data);
	}
	else {
		for (int i = 0; i < v.size() - 1; i++) {
			printf("%05d %d %05d\n", v[i].address, v[i].data,v[i+1].address);
		}
		printf("%05d %d -1", v[v.size()-1].address, v[v.size() - 1].data);
	}
	return 0;
}