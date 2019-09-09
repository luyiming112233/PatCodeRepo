#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 100010

struct node {
	int key, level, parent;
	node() {
		level = 0, parent = -1;
	}
}nodes[maxn];

int nid = 0;
vector<int> preOrder, inOrder;

int getNid() {
	return nid++;
}

void build(int preL, int preR, int inL, int inR, int level, int parent) {
	if (preL > preR) return;
	int value = preOrder[preL], index, id = getNid();
	for(int i=inL;i<=inR;i++)
		if (value == inOrder[i]) {
			index = i;
			break;
		}
	nodes[id].key = value, nodes[id].level = level, nodes[id].parent = parent;
	build(preL + 1, index - inL + preL, inL, index - 1, level + 1, id);
	build(index - inL + preL + 1, preR, index + 1, inR, level + 1, id);
}

int main() {
	int M, N,num,a,b,ina,inb;
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		preOrder.push_back(num);
	}
	inOrder = preOrder;
	sort(inOrder.begin(), inOrder.end());
	build(0, N - 1, 0, N - 1, -1, 0);
	for (int mi = 0; mi < M; mi++) {
		scanf("%d %d", &a, &b);
		for (ina = 0; ina < N; ina++) 
			if (a == nodes[ina].key) break;
		for (inb = 0; inb < N; inb++)
			if (b == nodes[inb].key) break;
		if (ina == N || inb == N) {
			if (ina == N && inb == N) printf("ERROR: %d and %d are not found.\n", a, b);
			else if (ina == N) printf("ERROR: %d is not found.\n", a);
			else if (inb == N)printf("ERROR: %d is not found.\n", b);
			continue;
		}
		while (nodes[ina].level > nodes[inb].level) ina = nodes[ina].parent;
		while (nodes[inb].level > nodes[ina].level) inb = nodes[inb].parent;
		while (nodes[ina].key != nodes[inb].key) {
			ina = nodes[ina].parent;
			inb = nodes[inb].parent;
		}
		int same = nodes[ina].key;
		if (same != a && same != b) printf("LCA of %d and %d is %d.\n", a, b, same);
		else if(same==a) printf("%d is an ancestor of %d.\n", a, b);
		else if(same==b) printf("%d is an ancestor of %d.\n", b, a);
	}
	return 0;
}
