#include<cstdio>
#include<vector>
using namespace std;

struct node {
	int key;
	node *left, *right;
	node() {
		left = NULL, right = NULL;
	}
};

vector<int> preOrder, postOrder;
bool flag = true, first = true;
int N;

node* build(int preL, int preR, int postL, int postR) {
	if (preL > preR) return NULL;
	node *newnode = new node();
	newnode->key = preOrder[preL];
	if (preL == preR) return newnode;
	int index, LC = preOrder[preL + 1], RC = postOrder[postR - 1];
	for (int i = postL; i <= postR; i++)
		if (postOrder[i] == LC) {
			index = i;
			break;
		}
	int len = index - postL;
	newnode->left = build(preL + 1, preL + 1 + len, postL, index);
	newnode->right = build(preL + 2 + len, preR, index + 1, preR - 1);
	if (postOrder[postR - 1] == preOrder[preL + 1]) flag = false;
	return newnode;
}

void inOrder(node* root) {
	if (root->left != NULL) inOrder(root->left);
	if (first) {
		printf("%d", root->key);
		first = false;
	}
	else
		printf(" %d", root->key);
	if (root->right != NULL) inOrder(root->right);
}

int main() {
	int num;
	node *root = NULL;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		preOrder.push_back(num);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		postOrder.push_back(num);
	}
	root = build(0, N - 1, 0, N - 1);
	if (flag) printf("Yes\n");
	else printf("No\n");
	inOrder(root);
	printf("\n");
	return 0;
}