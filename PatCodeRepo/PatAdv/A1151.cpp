#include<cstdio>
#include<vector>
using namespace std;

#define maxn 10010

struct node {
	int key;
	int parent;
	int level;
}nodes[maxn];

vector<int> inOrder, preOrder;
int id = 0;

int getId() {
	return id++;
}

void build(int preL,int preR,int inL,int inR,int level,int parent) {
	if (preL > preR)
		return;
	int nid = getId();
	int value = preOrder[preL];
	level++;
	nodes[nid].level=level;
	nodes[nid].key = value;
	nodes[nid].parent = parent;
	int index;
	for (int i = inL; i <= inR; i++) {
		if (value == inOrder[i]) {
			index = i;
			break;
		}
	}
	build(preL + 1, preL + index - inL, inL, index - 1, level, nid);
	build(preL + index - inL + 1, preR, index + 1, inR, level, nid);
}

int main() {
	int N, M,a,b;
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		inOrder.push_back(a);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		preOrder.push_back(a);
	}
	build(0, N - 1, 0, N - 1, 0, -1);
	for (int mi = 0; mi < M; mi++) {
		scanf("%d %d", &a, &b);
		int ina, inb;
		for (ina = 0; ina < N; ina++) {
			if (nodes[ina].key == a)
				break;
		}
		for (inb = 0; inb < N; inb++) {
			if (nodes[inb].key == b)
				break;
		}
		//not find
		if (ina == N || inb == N) {
			if (ina == N && inb == N)
				printf("ERROR: %d and %d are not found.\n", a, b);
			else if (ina == N)
				printf("ERROR: %d is not found.\n", a);
			else
				printf("ERROR: %d is not found.\n", b);
		}
		//find
		else {
			while (nodes[ina].level > nodes[inb].level) 
				ina = nodes[ina].parent;
			while (nodes[inb].level > nodes[ina].level)
				inb = nodes[inb].parent;
			while (nodes[ina].key != nodes[inb].key) {
				ina = nodes[ina].parent;
				inb = nodes[inb].parent;
			}
			int same = nodes[ina].key;
			if (same != a && same != b)
				printf("LCA of %d and %d is %d.\n", a, b,same);
			else if(same==a)
				printf("%d is an ancestor of %d.\n", same,b);
			else
				printf("%d is an ancestor of %d.\n", same, a);
		}
	}
	return 0;
}