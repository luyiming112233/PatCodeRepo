#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct node {
	int value;
	node* left;
	node* right;
	node() {
		left = NULL;
		right = NULL;
	}
};

vector<int> inorder, preorder, cpreorder;
bool first = true;

node* buildTree(int preL, int preR, int inL, int inR) {
	if (preL > preR)
		return NULL;
	node *newNode = new node();
	int index, len;
	for (index = inL; index <= inR; index++) {
		if (inorder[index] == preorder[preL])
			break;
	}
	if (index > inR)
		return NULL;
	newNode->value = preorder[preL];
	len = index - inL;
	newNode->left = buildTree(preL + 1, preL + len, inL, index - 1);
	newNode->right = buildTree(preL + len + 1, preR, index + 1, inR);
	return newNode;
}

node* buildMirrorTree(int preL, int preR, int inL, int inR) {
	if (preL > preR)
		return NULL;
	node *newNode = new node();
	int index, len;
	for (index = inL; index <= inR; index++) {
		if (inorder[index] == preorder[preL])
			break;
	}
	if (index > inR)
		return NULL;
	newNode->value = preorder[preL];
	len = index - inL;
	newNode->left = buildMirrorTree(preL + 1, preL + len, index + 1, inR);
	newNode->right = buildMirrorTree(preL + len + 1, preR, inL, index - 1);
	return newNode;
}

void treePreOrder(node *root) {
	if (root == NULL)
		return;
	cpreorder.push_back(root->value);
	treePreOrder(root->left);
	treePreOrder(root->right);
}


void treePostOrder(node *root) {
	if (root == NULL)
		return;
	treePostOrder(root->left);
	treePostOrder(root->right);
	if (first) {
		printf("%d", root->value);
		first = false;
	}
	else
		printf(" %d", root->value);
}

bool judge() {
	if (preorder.size() != cpreorder.size())
		return false;
	for (int i = 0; i < cpreorder.size(); i++) {
		if (preorder[i] != cpreorder[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int N, temp;
	node *root, *mirrorroot;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		inorder.push_back(temp);
		preorder.push_back(temp);
	}
	sort(inorder.begin(), inorder.end());
	root = buildTree(0, preorder.size() - 1, 0, inorder.size() - 1);
	mirrorroot = buildMirrorTree(0, preorder.size() - 1, 0, inorder.size() - 1);
	treePreOrder(root);
	bool same = true, mirrorsame = true;
	same = judge();
	cpreorder.clear();
	treePreOrder(mirrorroot);
	mirrorsame = judge();

	if (same) {
		printf("YES\n");
		treePostOrder(root);
	}
	else if (mirrorsame) {
		printf("YES\n");
		treePostOrder(mirrorroot);
	}
	else {
		printf("NO");
	}
	return 0;
}