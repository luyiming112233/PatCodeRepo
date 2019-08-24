#include<cstdio>
#include<string>
#include<string.h>
using namespace std;

#define slen 10

char op[slen];

struct node{
	int key;
	node *left, *right;
	node() {
		left = NULL, right = NULL;
	}
};

bool first = true;
int N;

void buildTree(node* &root) {
	if (N == 0)
		return;
	scanf("\n%s", &op);
	if ((string)op == "Push") {
		int key;
		scanf("%d", &key);
		root = new node();
		root->key = key;
		buildTree(root->left);
	}
	else if ((string)op == "Pop") {
		N--;
		return;
	}
	buildTree(root->right);
}

void postOrder(node *root) {
	if (root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	if (first) {
		first = false;
		printf("%d", root->key);
	}
	else {
		printf(" %d", root->key);
	}
}

int main() {
	node *root = NULL;
	scanf("%d", &N);
	buildTree(root);
	postOrder(root);
	return 0;
}