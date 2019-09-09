#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

struct node {
	int key;
	node *left, *right;
	node() {
		left = NULL;
		right = NULL;
	}
};

vector<int> preOrder, inOrder;

node *build(int preL,int preR,int inL,int inR) {
	if (preL > preR)
		return NULL;
	int value = preOrder[preL];
	int index;
	for (int i = inL; i <= inR; i++) {
		if (inOrder[i] == value) {
			index = i;
			break;
		}
	}
	node *root = new node();
	root->key = value;
	root->left = build(preL + 1, preL + index - inL, inL, index - 1);
	root->right = build(preL + index - inL + 1, preR, index + 1, inR);
	return root;

}

int find(node *root, int a, int b) {
	while (true) {
		if ((a >= root->key && b <= root->key) || (a <= root->key && b >= root->key)) {
			return root->key;
		}
		else if (a < root->key) {
			root = root->left;
		}
		else {
			root = root->right;
		}
	}
}

int main() {
	int M, N,K,num,a,b;
	bool ba, bb;
	scanf("%d %d", &M, &N);
	set<int> s;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		preOrder.push_back(num);
		s.insert(num);
	}
	inOrder = preOrder;
	sort(inOrder.begin(), inOrder.end());
	node *root = build(0, N - 1, 0, N - 1);
	for (int mi = 0; mi < M; mi++) {
		scanf("%d %d", &a, &b);
		ba = true, bb = true;
		if (s.find(a) == s.end())
			ba = false;
		if (s.find(b) == s.end())
			bb = false;
		if (ba&&bb) {
			int same = find(root, a, b);
			if (same != a && same != b) 
				printf("LCA of %d and %d is %d.\n", a, b, same);
			else if (same == a) 
				printf("%d is an ancestor of %d.\n", same, b);
			else if (same == b) 
				printf("%d is an ancestor of %d.\n", same, a);
			else 
				printf("LCA of %d and %d is %d.\n", a, b, same);
		}
		else {
			if (!ba && !bb) 
				printf("ERROR: %d and %d are not found.\n", a, b);
			else if (!ba) 
		        printf("ERROR: %d is not found.\n", a);
			else 
				printf("ERROR: %d is not found.\n", b);
		}
	}
	return 0;
}