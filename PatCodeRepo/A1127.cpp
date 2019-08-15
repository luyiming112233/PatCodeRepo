#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

#define maxn 35

struct node {
	int key;
	node *left, *right;
	node() {
		left = NULL;
		right = NULL;
	}
};

vector<int> postorder, inorder;

node* buildTree(int inLeft,int inRight,int postLeft,int postRight) {
	if (inLeft > inRight)
		return NULL;
	int value = postorder[postRight];
	int index;
	for (index = inLeft; index <= inRight; index++) {
		if (value == inorder[index]) {
			break;
		}
	}
	node *temp = new node();
	temp->key = value;
	temp->left = buildTree(inLeft, index - 1, postLeft, postLeft + index - inLeft - 1);
	temp->right = buildTree(index + 1, inRight, postLeft + index - inLeft, postRight - 1);
	return temp;
}

int main() {
	node *root = NULL,*qtemp;
	int N,num;
	vector<int> v,answer;
	queue<node*> q;
	node *r = new node(), *l = new node();
	r->key = -1, l->key = -2;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		inorder.push_back(num);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		postorder.push_back(num);
	}
	root = buildTree(0, N - 1, 0, N - 1);
	q.push(root);
	q.push(l);
	while (!q.empty()) {
		qtemp = q.front();
		q.pop();
		if (qtemp->key == -1) {
			for (int i = 0; i < v.size(); i++) {
				answer.push_back(v[i]);
			}
			v.clear();
			if(!q.empty())
				q.push(l);
		}
		else if (qtemp->key == -2) {
			for (int i = v.size()-1; i >=0 ; i--) {
				answer.push_back(v[i]);
			}
			v.clear();
			if (!q.empty())
				q.push(r);
		}
		else {
			v.push_back(qtemp->key);
			if (qtemp->left != NULL)
				q.push(qtemp->left);
			if (qtemp->right != NULL)
				q.push(qtemp->right);
		}
	}
	for (int i = 0; i < answer.size(); i++) {
		if (i == 0)
			printf("%d", answer[i]);
		else
			printf(" %d", answer[i]);
	}
	return 0;
}