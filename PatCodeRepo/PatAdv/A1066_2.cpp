#include<cstdio>

struct node {
	int key;
	int height;
	node *left, *right;
	node() {
		left = NULL;
		right = NULL;
		height = 1;
	}
};

int max(int a,int b) {
	if (a > b)
		return a;
	return b;
}

int getHeight(node *root) {
	if (root == NULL)
		return 0;
	return root->height;
}

void updateHeight(node *root) {
	root->height = max(getHeight(root->left), getHeight(root ->right)) + 1;
}

int getDiff(node *root) {
	return getHeight(root->left) - getHeight(root->right);
}

void L(node* &root) {
	node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void R(node* &root) {
	node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void insert(node* &root,int v) {
	if (root == NULL) {
		root = new node();
		root->key = v;
		return;
	}
	else {
		if (v < root->key) {
			insert(root->left, v);
			updateHeight(root);
			if (getDiff(root) == 2) {
				if (getDiff(root->left) == 1) {
					R(root);
				}
				else if (getDiff(root->left) == -1) {
					L(root->left);
					R(root);
				}
			}
		}
		else {
			insert(root->right, v);
			updateHeight(root);
			if (getDiff(root) == -2) {
				if (getDiff(root->right) == -1) {
					L(root);
				}
				else if (getDiff(root->right) == 1) {
					R(root->right);
					L(root);
				}
			}
		}
	}
}

int main() {
	int N,num;
	node *root = NULL;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		insert(root, num);
	}
	printf("%d", root->key);
	return 0;
}
