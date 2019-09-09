#include<cstdio>
#include<vector>
using namespace std;

vector<char> preOrder, inOrder;

struct node {
	char key;
	node *left, *right;
	node() {
		left = NULL, right = NULL;
	}
};

int len = 0;

node* build(int preL,int preR,int inL,int inR) {
	if (preL > preR) return NULL;
	char value = preOrder[preL];
	int index = -1;
	for (int i = inL; i <= inR; i++) {
		if (value == inOrder[i]) {
			index = i;
			break;
		}
	}
	node *newnode = new node();
	newnode->key = value;
	newnode->left = build(preL + 1, preL + index - inL, inL, index - 1);
	newnode->right = build(preL + index - inL + 1, preR, index + 1, inR);
	return newnode;
}

void DFS(node *root, int num) {
	num++;
	if (root->left == NULL && root->right == NULL) {
		if (num > len) len = num;
	}
	else {
		if (root->left != NULL) DFS(root->left, num);
		if (root->right != NULL) DFS(root->right, num);
	}
}

int main() {
	int N;
	scanf("%d\n",&N);
	char c;
	for (int i = 0; i < N; i++) {
		scanf("%c", &c);
		preOrder.push_back(c);
	}
	scanf("\n");
	for (int i = 0; i < N; i++) {
		scanf("%c", &c);
		inOrder.push_back(c);
	}
	node *root = build(0, N - 1, 0, N - 1);
	DFS(root, 0);
	printf("%d", len);

	return 0;
} 