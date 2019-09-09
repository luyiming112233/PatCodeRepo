#include<cstdio>

#define maxn 1010

struct node {
	int key;
	int right, left;
	node() {
		right = -1, left = -1;
	}
}nodes[maxn];

bool first;

void postOrder(int i) {
	if (nodes[i].left != -1)
		postOrder(2 * i);
	if (nodes[i].right != -1)
		postOrder(2 * i+1);
	if (first) {
		printf("%d", nodes[i].key);
		first = false;
	}
	else {
		printf(" %d", nodes[i].key);
	}
}

int main() {
	int M, N;
	scanf("%d %d", &M, &N);
	for (int i = 1; i <= N; i++) {
		if (2 * i <= N) {
			nodes[i].left = 2 * i;
		}
		if (2 * i +1<= N) {
			nodes[i].right = 2 * i+1;
		}
	}
	for (int mi = 0; mi < M; mi++) {
		for (int i = 1; i <= N; i++) {
			scanf("%d", &nodes[i].key);
		}
		bool isMax = false, isMin = false;
		for (int i = 1; i <= N; i++) {
			if (nodes[i].left != -1) {
			    if(nodes[i].key < nodes[2 * i].key)
					isMin = true;
				if (nodes[i].key > nodes[2 * i].key)
					isMax = true;;
			}
			if (nodes[i].right != -1) {
				if (nodes[i].key < nodes[2 * i+1].key)
					isMin = true;
				if (nodes[i].key > nodes[2 * i+1].key)
					isMax = true;;
			}
			if (isMax&&isMin)
				break;
		}
		if (isMax && isMin)
			printf("Not Heap\n");
		else if(isMax)
			printf("Max Heap\n");
		else
			printf("Min Heap\n");
		first = true;
		postOrder(1);
		printf("\n");
	}
	return 0;
}