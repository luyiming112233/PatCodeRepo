#include<cstdio>
#include<queue>
using namespace std;

#define maxn 20
bool flag = true;

struct node {
	int key;
	int left, right;
	node() {
		left = -1;
		right = -1;
	}
}nodes[maxn];

void levelOrder(int s) {
	queue<int> q;
	q.push(s);
	int qid;
	bool first = true;
	while (!q.empty()) {
		qid = q.front();
		q.pop();
		if (first) {
			printf("%d", nodes[qid].key);
			first = false;
		}
		else {
			printf(" %d", nodes[qid].key);
		}
		if (nodes[qid].left != -1) {
			q.push(nodes[qid].left);
		}
		if (nodes[qid].right != -1) {
			q.push(nodes[qid].right);
		}
	}
	printf("\n");
}

void inOrder(int root) {
	if (nodes[root].left != -1) {
		inOrder(nodes[root].left);
	}
	if (flag) {
		printf("%d", nodes[root].key);
		flag = false;
	}
	else {
		printf(" %d", nodes[root].key);
	}
	if (nodes[root].right != -1) {
		inOrder(nodes[root].right);
	}
}

int main() {
	int N;
	char sl,sr;
	int isRoot[maxn] = { 0 };
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		//读入的时候就完成交换
		scanf("\n%c %c", &sr, &sl);
		if (sr != '-') {
			nodes[i].right = sr - '0';
			isRoot[sr - '0'] = 1;
		}
		if (sl != '-') {
			nodes[i].left = sl - '0';
			isRoot[sl - '0'] = 1;
		}
		nodes[i].key = i;
	}
	int root = -1;
	for (int i = 0; i < N; i++) {
		if (isRoot[i] == 0) {
			root = i;
			break;
		}
	}
	levelOrder(root);
	inOrder(root);
	return 0;
}