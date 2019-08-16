#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define maxn 100010

struct node {
	int address;
	int data;
	int next;
	int rank;
	int t;
}nodes[maxn];

bool cmp(node a, node b) {
	if(a.rank!=b.rank)
    	return a.rank > b.rank;
	return a.t < b.t;
}

int main() {
	int start, N, K,address,t=0;
	vector<node> v;
	scanf("%d %d %d", &start, &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &address);
		nodes[address].address = address;
		scanf("%d %d", &nodes[address].data, &nodes[address].next);
		if (nodes[address].data < 0) {
			nodes[address].rank = 2;
		}
		else if (nodes[address].data <= K) {
			nodes[address].rank = 1;
		}
		else {
			nodes[address].rank = 0;
		}
	}
	while (start != -1) {
		nodes[start].t = t;
		t++;
		v.push_back(nodes[start]);
		start = nodes[start].next;
	}
	sort(v.begin(), v.end(), cmp);
	if (v.size() == 0)
		return 0;
	if (v.size() == 1) {
		printf("%05d %d -1", v[0].address, v[0].data);
	}
	else {
		for (int i = 0; i < v.size() - 1; i++) {
			printf("%05d %d %05d\n", v[i].address, v[i].data,v[i+1].address);
		}
		printf("%05d %d -1", v.back().address, v.back().data);
	}
	return 0;
}