#include<cstdio>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;

#define slen 15
#define maxn 25

struct node {
	char str[slen];
	int left_child, right_child;
}nodes[maxn];

bool isRoot[maxn];
bool first = true;

void DFS(int i) {
	if (nodes[i].left_child==-1 && nodes[i].right_child == -1) {
		printf("%s", nodes[i].str);
	}
	else {
		if (first) {
			first = false;
			if (nodes[i].left_child != -1) {
				DFS(nodes[i].left_child);
			}
			printf("%s", nodes[i].str);
			if (nodes[i].right_child != -1) {
				DFS(nodes[i].right_child);
			}
		}
		else {
			printf("(");
			if (nodes[i].left_child != -1) {
				DFS(nodes[i].left_child);
			}
			printf("%s", nodes[i].str);
			if (nodes[i].right_child != -1) {
				DFS(nodes[i].right_child);
			}
			printf(")");
		}
	}
}

int main() {
	int N,root;
	fill(isRoot, isRoot + maxn, true);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("\n%s %d %d", nodes[i].str, &nodes[i].left_child, &nodes[i].right_child);
		if(nodes[i].left_child!=-1)
    		isRoot[nodes[i].left_child] = false;
		if(nodes[i].right_child!=-1)
    		isRoot[nodes[i].right_child] = false;
	}
	for (root = 1; root <= N; root++) {
		if (isRoot[root]) {
			break;
		}
	}
	DFS(root);
	return 0;
}