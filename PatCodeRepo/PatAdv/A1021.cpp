#include<cstdio>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define maxn 10010

bool nodes[maxn];
vector<int>mv [maxn];

bool isConnect(int a, int b) {
	bool find = false;
	for (int i = 0; i < mv[a].size(); i++) {
		if (mv[a][i] == b) {
			find = true;
			break;
		}
	}
	if (!find) {
		for (int i = 0; i < mv[b].size(); i++) {
			if (mv[b][i] == a) {
				find = true;
				break;
			}
		}
	}
	return find;
}

void connectInsert(int a, int b) {
	mv[a].push_back(b);
	mv[b].push_back(a);
}

int main() {
	int N,a,b,k,num,node,maxlen=0,len=0;
	vector<int> v;
	scanf("%d", &N);
	fill(nodes, nodes + maxn, 0);
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
				if (isConnect(node,i) && nodes[i]==0) {
					q.push(i);
					num++;
					nodes[i] = 1;
				}
			}
		}
	}
	if (k == 1) {
		for (int i = 1; i <= N; i++) {
			num = 0;
			len = 0;
			fill(nodes, nodes + maxn, 0);
			node = i;
			q.push(node);
			q.push(0);
			num++;
			while (!q.empty()) {
				node = q.front();
				q.pop();
				if (node == 0) {
					len++;
					if (!q.empty())
						q.push(0);
					continue;
				}
				else {
					for (int j = 1; j <= N; j++) {
						if (nodes[j] == 0 && isConnect(node, j)) {
							q.push(j);
							num++;
							nodes[j] = 1;
						}
					}
				}
			}
			//计算出当前深度,更新答案
			if (len > maxlen) {
				v.clear();
				v.push_back(i);
				maxlen = len;
			}
			else if (len == maxlen) {
				v.push_back(i);
			}
		}
		//输出结果
		bool first = true;
		for (int i = 0; i < v.size(); i++) {
			if (first) {
				printf("%d", v[i]);
				first = false;
			}
			else {
				printf("\n%d", v[i]);
			}
		}
	}
	else {
		printf("Error: %d components", k);
	}
}