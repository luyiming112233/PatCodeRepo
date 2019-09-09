/*
1.使用 先序/后序+中序 构建二叉树
2.对于BST 可通过排序得到中序遍历（需要注意BST是否会出现值相同的节点）
*/
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

struct node {
	int key;
	node *left, *right;
	node() {
		left = NULL, right = NULL;
	}
};

vector<int> postOrder, inOrder;

node *build(int postL, int postR, int inL, int inR) {
	if (postL > postR) return NULL;
	int value = postOrder[postR], index;
	for(int i=inL;i<=inR;i++)
		if (value == inOrder[i]) {
			index = i;
			break;
		}
	node *newnode = new node();
	newnode->key = value;
	newnode->left = build(postL, index - 1 - inL + postL, inL, index - 1);
	newnode->right = build(index - inL + postL, postR - 1, index + 1, inR);
	return newnode;
}

int main() {
	int N,num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		postOrder.push_back(num);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		inOrder.push_back(num);
	}
	node *root = build(0, N - 1, 0, N - 1);
	bool first = true;
	queue<node*> q;
	node* qid;
	q.push(root);
	while (!q.empty()) {
		qid = q.front();
		q.pop();
		if (first) {
			first = false;
			printf("%d", qid->key);
		}else printf(" %d", qid->key);
		if (qid->left != NULL) q.push(qid->left);
		if (qid->right != NULL) q.push(qid->right);
	}
	return 0;
}