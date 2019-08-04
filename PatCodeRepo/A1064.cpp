#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define maxn 1010

int N,index=-1;
vector<int> v;

struct node {
	int key;
	int left, right;
	node() {
		left = -1;
		right = -1;
	}
}nodes[maxn];

int getValue() {
	index++;
	return v[index];
}

void inOrderInsert(int i) {
	if (nodes[i].left != -1) {
		inOrderInsert(nodes[i].left);
	}
	nodes[i].key = getValue();
	if (nodes[i].right != -1) {
		inOrderInsert(nodes[i].right);
	}
}

int main() {
	int num,nid;
	bool first = true;
	queue<int> q;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		if (i * 2 + 1 < N) {
			nodes[i].left = i * 2 + 1;
		}
		if (i * 2 + 2 < N) {
			nodes[i].right = i * 2 + 2;
		}
	}
	inOrderInsert(0);
	q.push(0);
	while (!q.empty()) {
		nid = q.front();
		q.pop();
		if (first) {
			printf("%d", nodes[nid].key);
			first = false;
		}else{
			printf(" %d", nodes[nid].key);
		}
		if (nodes[nid].left != -1) {
			q.push(nodes[nid].left);
		}
		if (nodes[nid].right != -1) {
			q.push(nodes[nid].right);
		}
	}
	return 0;
}
