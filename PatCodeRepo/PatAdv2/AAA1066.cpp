#include<cstdio>
#include<algorithm>
using namespace std;

struct node {
	int key,level;
	node *left, *right;
	node() {
		level = 1, left = NULL, right = NULL;
	}
}nodetemp;

/*int getH(node *root) {
	if (root == NULL) return 0;
	return max(getH(root->left), getH(root->right)) + 1;
}*/

int getH(node *root) {
	if (root == NULL) return 0;
	return root->level;
}

void updateH(node *root) {
    root->level = max(getH(root->left), getH(root->right)) + 1;
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

void insert(node* &root, int value) {
	if (root == NULL) {
		root = new node();
		root->key = value;
		return;
	}
	if (value < root->key) {
		insert(root->left, value);
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
		scanf("%d", &num);;
		insert(root, num);
	}
	printf("%d\n", root->key);
	return 0;
}