#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 100010

int nodes[maxn];

int main() {
	fill(nodes, nodes + maxn, -1);
	int l1, l2,N,add,next,minlen;
	vector<int> v1, v2;
	char c;
	scanf("%d %d %d", &l1, &l2, &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %c %d", &add, &c, &next);
		nodes[add] = next;
	}
	while (l1 != -1) {
		v1.push_back(l1);
		l1 = nodes[l1];
	}
	while (l2 != -1) {
		v2.push_back(l2);
		l2 = nodes[l2];
	}
	minlen = v1.size();
	if (minlen > v2.size())
		minlen = v2.size();
	int same = -1;
	for (int i = 0; i < minlen; i++) {
		if (v1[v1.size() - 1 - i] == v2[v2.size() - 1 - i])
			same = v1[v1.size() - 1 - i];
		else
			break;
	}
	if (same != -1)
		printf("%05d", same);
	else
		printf("-1");
	return 0;
}