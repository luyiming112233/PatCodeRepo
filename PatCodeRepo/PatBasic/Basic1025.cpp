#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

struct node {
	int address, data, next;
}nodes[100010];

int main() {
	int first;
	int n, k, i, address;
	vector<struct node> vs;
	struct node temp;
	scanf("%d %d %d", &first, &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &address);
		nodes[address].address = address;
		scanf("%d %d", &nodes[address].data, &nodes[address].next);
	}

	while (first != -1) {
		vs.push_back(nodes[first]);
		first = nodes[first].next;
	}

	for (int t = 0; t < vs.size() / k; t++)
		reverse(vs.begin() + t * k, vs.begin() + t * k + k);

	for (i = 0; i < vs.size() - 1; i++) {//在这里vs.size不能用n代替，可能存在无效的节点
		printf("%05d %d %05d\n", vs[i].address, vs[i].data, vs[i + 1].address);
	}
	if (vs.size() != 0)
		printf("%05d %d %d\n", vs[i].address, vs[i].data, -1);
	return 0;
}