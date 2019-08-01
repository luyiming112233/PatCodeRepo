#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool flag = false;

vector<int> preorder,cpreorder,postorder;

struct node {
	int value;
	node* left;
	node* right;
	node() {
		left = NULL;
		right = NULL;
	}
};

void insert(node* &root,int value) {
	if (root == NULL) {
		node *newNode = new node();
		newNode->value = value;
		root = newNode;
	}
	else if (value < root->value) {
		insert(root->left, value);
	}
	else {
		insert(root->right, value);
	}
}

void treeInOrder(node *root) {
	if (root == NULL)
		return;
	cpreorder.push_back(root->value);
	//¾µÏñ
	if (flag) {
		treeInOrder(root->right);
		treeInOrder(root->left);
	}
	else {
		treeInOrder(root->left);
		treeInOrder(root->right);
	}
}

bool judge() {
	if (preorder.size() != cpreorder.size())
		return false;
	for (int i = 0; i < preorder.size(); i++) {
		if (preorder[i] != cpreorder[i])
			return false;
	}
	return true;
}

//ºóÐò±éÀú
void treePostOrder(node *root) {
	if (root == NULL)
		return;
	//¾µÏñ
	if (flag) {
		treePostOrder(root->right);
		treePostOrder(root->left);
	}
	else {
		treePostOrder(root->left);
		treePostOrder(root->right);
	}
	postorder.push_back(root->value);
}

int main() {
	int N,temp;
	scanf("%d", &N);
	node *root = NULL;
	bool same, mirrorsame;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		preorder.push_back(temp);
		insert(root, temp);
	}
	treeInOrder(root);
	same = judge();
	if (same == false) {
		cpreorder.clear();
		flag = true;
		treeInOrder(root);
		same = judge();
	}
	if (same) {
		treePostOrder(root);
		printf("YES\n");
		for (int i = 0; i < postorder.size(); i++) {
			if (i == 0)
				printf("%d", postorder[i]);
			else {
				printf(" %d", postorder[i]);
			}
		}
	}
	else {
		printf("NO");
	}
	return 0;
}