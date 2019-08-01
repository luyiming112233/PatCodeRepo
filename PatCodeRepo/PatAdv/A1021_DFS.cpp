#include<cstdio>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;

#define maxn 10010

bool nodes[maxn];
int nodelen[maxn],finallen[maxn];
int N;
set<int> s;

bool isConnect(int a, int b) {
	if (s.find(a * maxn + b) != s.end() || s.find(a + b * maxn) != s.end()) {
		return true;
	}
	return false;
}

void connectInsert(int a, int b) {
	s.insert(a * maxn + b);
	s.insert(b * maxn + a);
}

void DFS(int root,int deep) {
	nodes[root] = 1;
	for (int i = 1; i <= N; i++) {
		if (isConnect(root, i) && nodes[i] == 0) {
			DFS(i, deep + 1);
		}
	}
	if (deep > finallen[root])
		finallen[root] = deep;
}

void search(int root) {
	fill(nodes, nodes + maxn, 0);
	//fill(nodelen, nodelen + maxn, 0);
	DFS(root,1);
}

int main() {
	int a, b, k, num, node, maxlen = 0, len = 0;
	set<int> answer,answer2;
	scanf("%d", &N);
	fill(nodes, nodes + maxn, 0);
	//fill(nodelen, nodelen + maxn, 0);
	fill(finallen, finallen + maxn, 0);
	for (int i = 1; i < N; i++) {
		scanf("%d%d", &a, &b);
		connectInsert(a, b);
	}
	//计算连通域
	k = 0;
	num = 0;
	queue<int> q;

	while (num != N) {
		k++;
		//找一个没有连通的节点
		for (node = 1; node <= N; node++) {
			if (nodes[node] == 0) {
				q.push(node);
				nodes[node] = 1;
				num++;
				break;
			}
		}
		while (!q.empty()) {
			node = q.front();
			q.pop();
			for (int i = 1; i <= N; i++) {
				if (isConnect(node, i) && nodes[i] == 0) {
					q.push(i);
					num++;
					nodes[i] = 1;
				}
			}
		}
	}
	if (k == 1) {
		search(1);
		maxlen = 0;
		set<int>::iterator it;
		for (int i = 1; i <= N; i++) {
			if (finallen[i] > maxlen) {
				answer.clear();
				maxlen = finallen[i];
				answer.insert(i);
			}
			else if (finallen[i] == maxlen) {
				answer.insert(i);
			}
		}
		search(*answer.begin());
		for (int i = 1; i <= N; i++) {
			if (finallen[i] > maxlen) {
				answer2.clear();
				maxlen = finallen[i];
				answer2.insert(i);
			}
			else if (finallen[i] == maxlen) {
				answer2.insert(i);
			}
		}
		for (it = answer2.begin(); it != answer2.end(); it++) {
			answer.insert(*it);
		}

		//输出结果
		bool first = true;
		for (it = answer.begin(); it != answer.end();it++) {
			if (first) {
				printf("%d", *it);
				first = false;
			}
			else {
				printf("\n%d", *it);
			}
		}
	}
	else {
		printf("Error: %d components", k);
	}
}