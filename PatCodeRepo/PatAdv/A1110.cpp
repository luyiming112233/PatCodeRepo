#include<cstdio>
#include<queue>
using namespace std;

#define maxn 25

struct node {
	int left, right;
}nodes[maxn];

int trans(char *str) {
	if (str[0] == '-')
		return -1;
	int n = 0;
	for (int i = 0; i < maxn; i++) {
		if (str[i] == '\0')
			break;
		n = n * 10 + str[i] - '0';
	}
	return n;
}

int main() {
	int N,nid;
	scanf("%d", &N);
	int isRoot[maxn] = { 0 };
	char str[maxn];
	bool flag = true, isCom = true;
	for (int i = 0; i < N; i++) {
		scanf("\n%s", str);
		nodes[i].left = trans(str);
		scanf("%s", str);
		nodes[i].right = trans(str);
		if (nodes[i].left != -1)
			isRoot[nodes[i].left] = 1;
		if (nodes[i].right != -1)
			isRoot[nodes[i].right] = 1;
	}
	int root=-1;
	for (int i = 0; i < maxn; i++) {
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
		//满节点或者有左儿子
		if (flag) {
			if (nodes[nid].left != -1 && nodes[nid].right != -1) {
				q.push(nodes[nid].left);
				q.push(nodes[nid].right);
			}
			else if (nodes[nid].left != -1 && nodes[nid].right == -1) {
				q.push(nodes[nid].left);
				flag = false;
			}
			else if (nodes[nid].left == -1 && nodes[nid].right == -1) {
				flag = false;
			}
			else {
				isCom = false;
				break;
			}
		}
		else {
			if (!(nodes[nid].left == -1 && nodes[nid].right == -1)) {
				isCom = false;
				break;
			}
		}
	}
	if (isCom) {
		printf("YES %d", nid);
	}
	else {
		printf("NO %d", root);
	}
	return 0;
}