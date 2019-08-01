#include<cstdio>
#include<queue>
using namespace std;

#define maxn 30

int in[maxn], post[maxn], N;

struct node {
	int v;
	node *left;
	node *right;
};

node *create(int inL, int inR, int postL, int postR) {
	if (inL > inR)
		return NULL;
	node *root = new node();
	root->v = post[postR];
	int index,num;
	for (index = inL; index <= inR; index++) {
		if (in[index] == post[postR])
			break;
	}
	num = index - inL;
	root->left = create(inL,index-1,postL,postL+num-1);
	root->right = create(index + 1, inR, postL + num, postR - 1);
	return root;
}

void BFS(node *root) {
	queue<node*> q;
	bool first = true;
	q.push(root);
	node *n;
	while (!q.empty()) {
		n = q.front();
		q.pop();
		if (first) {
			printf("%d", n->v);
			first = false;
		}
		else {
			printf(" %d", n->v);
		}
		if (n->left != NULL) {
			q.push(n->left);
		}
		if (n->right != NULL) {
			q.push(n->right);
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &post[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &in[i]);
	node *root = create(0, N - 1, 0, N - 1);
	BFS(root);
	return 0;
}