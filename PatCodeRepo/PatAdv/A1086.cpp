#include<cstdio>
#include<stack>
#include<string.h>
using namespace std;

struct node {
	int value;
	node *left;
	node *right;
	node() {
		left = NULL;
		right = NULL;
	}
};

bool leftChild = true;
bool first = true;
stack<node*> s;

node* push(node* sn,int value) {
	node *newNode = new node();
	newNode->value = value;
	if (leftChild) {
		sn->left = newNode;
	}
	else {
		sn->right = newNode;
	}
	leftChild = true;
	s.push(newNode);
	return newNode;
}

node* pop() {
	//½øÈëÓÒ×ÓÊ÷
	leftChild = false;
	node* parentNode = s.top();
	s.pop();
	return parentNode;
}

void postorder(node* root) {
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	if (first) {
		printf("%d", root->value);
		first = false;
	}
	else {
		printf(" %d", root->value);
	}
}

int main() {
	int N,value;
	char op[10];
	
	node root,*snode=&root;
	scanf("%d", &N);
	for (int i = 0; i < 2 * N; i++) {
		scanf("%s", op);
		if (strcmp(op, "Push") == 0) {
			scanf("%d", &value);
			snode = push(snode, value);
		}
		if (strcmp(op, "Pop") == 0) {
			snode = pop();
		}
	}
	postorder(root.left);
	return 0;
}