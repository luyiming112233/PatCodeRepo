#include<cstdio>
#include<queue>
using namespace std;

struct node {
	int key;
	int red;
	node *left, *right;
	node() {
		left = NULL, right = NULL, red = 0;
	}
};

void insert(node* &root,int key,int red) {
	if (root == NULL) {
		root = new node();
		root->key = key;
		root->red = red;
		return;
	}
	if (key < root->key) insert(root->left, key, red);
	else insert(root->right, key, red);
}

bool kidBlack(node *root) {
	if (root != NULL && root->red == 1) {
		if (root->left != NULL && root->left->red == 1) return false;
		if (root->right != NULL && root->right->red == 1) return false;
	}
	return true;
}

int calPath(node *root) {
	if (root == NULL)
		return 0;
	int Bleft, Bright;
	Bleft = calPath(root->left);
	Bright = calPath(root->right);
	if (Bleft != Bright || Bleft==-1 || Bright==-1) return -1;
	if (root->red == 0) return Bleft + 1;
	else return Bleft;
}

bool judge(node *root) {
	if (root->red == 1) return false;
	if (calPath(root) == -1) return false;
	queue<node*> q;
	q.push(root);
	node *temp;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (!kidBlack(temp)) return false;
		if (temp != NULL) {
			if (temp->left != NULL) q.push(temp->left);
			if (temp->right != NULL) q.push(temp->right);
		}
	}
	return true;
}

int main() {
	int K, N,num;
	node *root;
	scanf("%d", &K);
	for (int ki = 0; ki < K; ki++) {
		scanf("%d", &N);
		root = NULL;
		for (int i = 0; i < N; i++) {
			scanf("%d", &num);
			if (num < 0) insert(root, -num, 1);
			else insert(root, num, 0);
		}
		if (judge(root)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}