#include<cstdio>
#include<queue>
using namespace std;

#define maxn 1010

struct node {
	int key;
	int deep;
	node *left, *right;
	node() {
		left = NULL;
		right = NULL;
	}
}nodes[maxn];

void insert(node* &root,int value) {
	if (root == NULL) {
		root = new node();
		root->key = value;
		return;
	}
	if (value <= root->key) {
		insert(root->left, value);
	}
	else {
		insert(root->right, value);
	}
}

int main() {
	node* root = NULL,*temp;
	int N,num;
	int ds[maxn] = { 0 };
	vector<int> v;
	queue<node*> q;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		insert(root, num);
	}
	if (N == 1) {
		printf("1 + 0 = 1");
		return 0;
	}
	q.push(root);
	root->deep = 0;
	while (!q.empty()) {
		temp= q.front();
		q.pop();
		ds[temp->deep]++;
		if (temp->left != NULL) {
			temp->left->deep = temp->deep + 1;
			q.push(temp->left);
		}
		if (temp->right != NULL) {
			temp->right->deep = temp->deep + 1;
			q.push(temp->right);
		}
	}
	int n1=ds[1], n2=ds[0];
	for (int i = 1; i < maxn; i++) {
		if (ds[i] != 0) {
			n1 = ds[i];
			n2 = ds[i-1];
		}
		else {
			break;
		}
	}
	printf("%d + %d = %d", n1, n2, n1 + n2);
	return 0;
}