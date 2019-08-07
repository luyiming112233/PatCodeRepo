#include<vector>
#include<cstdio>
#include<queue>
using namespace std;

#define maxn 20

struct node {
	int left, right;
	node() {
		left = -1;
		right = -1;
	}
}nodes[maxn];

int isRoot[maxn] = { 0 };

int main() {
	int N,root,nid;
	vector<int> leaf;
	char c1,c2;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("\n%c %c", &c1, &c2);
		if (c1 != '-') {
			nodes[i].left = c1 - '0';
			isRoot[c1 - '0'] = 1;
		}
		if (c2 != '-') {
			nodes[i].right = c2 - '0';
			isRoot[c2 - '0'] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		if (isRoot[i] == 0) {
			root = i;
			break;
		}
	}
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		nid = q.front();
		q.pop();
		if (nodes[nid].left == -1 && nodes[nid].right == -1) {
			leaf.push_back(nid);
		}
		else {
			if (nodes[nid].left != -1) {
				q.push(nodes[nid].left);
			}
			if (nodes[nid].right != -1) {
				q.push(nodes[nid].right);
			}
		}
	}
	for (int i = 0; i < leaf.size(); i++) {
		if (i == 0)
			printf("%d", leaf[i]);
		else
			printf(" %d", leaf[i]);
	}
	return 0;
}