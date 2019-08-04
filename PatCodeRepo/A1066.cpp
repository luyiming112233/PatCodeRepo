#include<cstdio>

struct node {
	int key;
	int height;
	node *left, *right;
	node() {
		height = 1;
		left = NULL;
		right = NULL;
	}
};

int max(int a, int b) {
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
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

int getDiff(node *root) {
	return getHeight(root->left) - getHeight(root->right);
}

void L(node* &root) {
	node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	updateHeight(root);// 更新树高
	updateHeight(temp);// 更新树高
	root = temp;
}

void R(node* &root) {
	node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updateHeight(root);// 更新树高
	updateHeight(temp);// 更新树高
	root = temp;
}

void insert(node* &root, int value) {
	if (root == NULL) {
		root = new node();
		root->key = value;
		return;
	}
	else {
		if (value < root->key) {
			insert(root->left, value);
			updateHeight(root);// 更新树高
			int diff = getDiff(root);
			if (diff == 2) {
				int ldiff = getDiff(root->left);
				if (ldiff == 1) {//LL
					R(root);
				}
				else if (ldiff == -1) {//LR
					L(root->left);
					R(root);
				}
			}
			
		}
		else if (value >= root->key) {
			insert(root->right, value);
			updateHeight(root);// 更新树高
			int diff = getDiff(root);
			if (diff == -2) {
				int rdiff = getDiff(root->right);
				if (rdiff == -1) {//RR
					L(root);
				}
				else if (rdiff == 1) {//RL
					R(root->right);
					L(root);
				}
			}
		}
	}
}

int main() {
	node* root = NULL;
	int N,num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		insert(root, num);
	}
	printf("%d", root->key);
	return 0;
}