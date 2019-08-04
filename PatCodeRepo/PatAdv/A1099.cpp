#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#define maxn 110

int N;
int index=-1;
vector<int> v;

struct node {
	int value;
	int left;
	int right;
}tree[maxn];

int getValue() {
	index++;
	return v[index];
}

void inOrderInsert(int i) {
	if (tree[i].left != -1)
		inOrderInsert(tree[i].left);
	tree[i].value = getValue();
	if (tree[i].right != -1)
		inOrderInsert(tree[i].right);
}

int main() {
	scanf("%d", &N);
	int num,tid;
	node temp;
	bool first = true;
	queue<int> q;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &tree[i].left, &tree[i].right);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	inOrderInsert(0);
	q.push(0);
	while (!q.empty()) {
		tid = q.front();
		q.pop();
		if (first) {
			printf("%d", tree[tid].value);
			first = false;
		}else{
			printf(" %d", tree[tid].value);
		}
		if (tree[tid].left != -1)
			q.push(tree[tid].left);
		if (tree[tid].right != -1)
			q.push(tree[tid].right);
	}
	return 0;
}