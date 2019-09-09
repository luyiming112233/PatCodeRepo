#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define maxn 10010

struct node {
	int key, parent, level;
	node() {
		level = 1;
	}
}nodes[maxn];

int id = 0;

int getId() {
	return id++;
}

vector<int> inOrder, preOrder;

void build(int preL, int preR, int inL, int inR, int father,int level) {
	if (preL > preR)
		return;
	int nid = getId();
	int value = preOrder[preL];
	int index;
	level++;
	for (int i = inL; i <= inR; i++) {
		if (value == inOrder[i]) {
			index = i;
			break;
		}
	}
	nodes[nid].key = value;
	nodes[nid].level = level;
	nodes[nid].parent = father;
	build(preL + 1, preL + index - inL, inL, index - 1, nid, level);
	build(preL + index - inL + 1, preR, index + 1, inR, nid, level);
}


int main() {
	int M, N, K, num, a, b;
	int ina, inb;
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		preOrder.push_back(num);
	}
	inOrder = preOrder;
	sort(inOrder.begin(), inOrder.end());
	build(0, N - 1, 0, N - 1, -1, 1);
	for (int mi = 0; mi < M; mi++) {
		scanf("%d %d", &a, &b);
		for (ina = 0; ina < N; ina++)
			if (nodes[ina].key == a)
				break;
		for (inb = 0; inb < N; inb++)
			if (nodes[inb].key == b)
				break;
		if (ina != N && inb != N) {
			while (nodes[ina].level > nodes[inb].level) {
				ina = nodes[ina].parent;
			}
			while (nodes[ina].level < nodes[inb].level) {
				inb = nodes[inb].parent;
			}
			while (nodes[ina].key != nodes[inb].key) {
				ina = nodes[ina].parent;
				inb = nodes[inb].parent;
			}
			int same = nodes[ina].key;
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
		    if(ina==N && inb ==N)
				printf("ERROR: %d and %d are not found.\n", a, b);
			else if(ina==N)
				printf("ERROR: %d is not found.\n", a);
			else
				printf("ERROR: %d is not found.\n", b);
		}
	}

}