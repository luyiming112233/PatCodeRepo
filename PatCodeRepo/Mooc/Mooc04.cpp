#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define maxn 15

struct node {
	node *right, *left;
	int key;
	node() {
		right = NULL;
		left = NULL;
	}
}nodes[maxn];

vector<int> vr, vc;

void insert(node* &root,int value) {
	if (root == NULL) {
		root = new node();
		root->key = value;
		return;
	}
	if(value<=root->key){
		insert(root->left, value);
	}
	else {
		insert(root->right, value);
	}
}

void levelOrder(node *root,vector<int> &v) {
	node *t;
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		t = q.front();
		q.pop();
		v.push_back(t->key);
		if (t->left != NULL) {
			q.push(t->left);
		}
		if (t->right != NULL) {
			q.push(t->right);
		}
	}
}

bool judge(node *root,node *croot) {
	vr.clear();
	vc.clear();
	levelOrder(root, vr);
	levelOrder(croot, vc);
	if (vr.size() != vc.size()) {
		return false;
	}
	for (int i = 0; i < vr.size(); i++) {
		if (vr[i] != vc[i])
			return false;
	}
	return true;
}

int main() {
	int N, L,num;
	node *root, *croot;
	bool flag;
	while (true) {
		scanf("%d", &N);
		root = NULL;
		if (N == 0)
			break;
		scanf("%d", &L);
		for (int i = 0; i < N; i++) {
			scanf("%d", &num);
			insert(root, num);
		}
		for (int j = 0; j < L; j++) {
			croot = NULL;
			for (int i = 0; i < N; i++) {
				scanf("%d", &num);
				insert(croot, num);
			}
			if (judge(root, croot)) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
		}
	}
	return 0;
}