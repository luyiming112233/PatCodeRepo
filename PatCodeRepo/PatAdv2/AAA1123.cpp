#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

struct node {
	int key, height;
	node *left, *right;
	node() {
		height = 1, left = NULL, right = NULL;
	}
};

int getH(node *root) {
	if (root == NULL) return 0;
	else return root->height;
}

void updateH(node *root) {
	root->height = max(getH(root->left), getH(root->right)) + 1;
}

int getDiff(node *root) {
	return getH(root->left) - getH(root->right);
}

void L(node* &root) {
	node *temp = root->right;
	root->right = temp->left;
	temp->left = root;
	root = temp;
	updateH(root->left);
	updateH(root);
}

void R(node* &root) {
	node *temp = root->left;
	root->left = temp->right;
	temp->right = root;
	root = temp;
	updateH(root->right);
	updateH(root);
}

void insert(node* &root,int value) {
	if (root == NULL) {
		root = new node();
		root->key = value;
		return;
	}
	if (value < root->key) {
		insert(root->left,value);
		updateH(root);
		int diff = getDiff(root), ldiff = getDiff(root->left);
		if (diff == 2) {
			if (ldiff == 1) {
				R(root);
			}
			else if (ldiff == -1) {
				L(root->left);
				R(root);
			}
		}
	}
	else {
		insert(root->right, value);
		updateH(root);
		int diff = getDiff(root), rdiff = getDiff(root->right);
		if (diff == -2) {
			if (rdiff == -1) {
				L(root);
			}
			else if (rdiff == 1) {
				R(root->right);
				L(root);
			}
		}
	}
}

int main() {
	int N, num;
	node* root = NULL;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		insert(root, num);
	}
	queue<node*> q;
	node* qid;
	q.push(root);
	bool flag = true, isCom = true, first = true;
	while (!q.empty()) {
		qid = q.front();
		q.pop();
		if (first) {
			first = false;
			printf("%d", qid->key);
		}else printf(" %d", qid->key);
		if (qid->left != NULL) {
			if (!flag) isCom = false;
			q.push(qid->left);
		}
		else if (flag) {
			flag = false;
		}
		if (qid->right != NULL) {
			if (!flag) isCom = false;
			q.push(qid->right);
		}
		else if (flag) {
			flag = false;
		}
	}
	if (isCom) printf("\nYES");
	else printf("\nNO");
	return 0;
}