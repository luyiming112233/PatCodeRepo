#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;

#define maxn 10010

bool connect[maxn];
vector<int> mat[maxn];

vector<int> BFS(int deep) {
	int qid;
	vector<int> temp;
	fill(connect, connect + maxn, false);
	queue<int> tq;
	connect[deep] = true;
	tq.push(deep);
	tq.push(-1);
	while (!tq.empty()) {
		qid = tq.front();
		tq.pop();
		if (qid == -1) {
			if (!tq.empty()) {
				temp.clear();
				tq.push(-1);
			}
		}
		else {
			temp.push_back(qid);
			for (int i = 0; i < mat[qid].size(); i++) {
				if (connect[mat[qid][i]] == false) {
					connect[mat[qid][i]] = true;
					tq.push(mat[qid][i]);
				}
			}
		}
	}
	return temp;
}

int main() {
	int N,a,b,index;
	vector<int> answer,temp;
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		scanf("%d %d", &a, &b);
		mat[a].push_back(b);
		mat[b].push_back(a);
	}
	int K=0,deep=-1,qid;
	fill(connect, connect + maxn,false);
	for (int ni = 1; ni <= N; ni++) {
		if (connect[ni] == false) {
			K++;
			queue<int> q;
			q.push(ni);
			q.push(-1);
			connect[ni] = true;
			while (!q.empty()) {
				qid = q.front();
				q.pop();
				if (qid != -1) {
					deep = qid;
					for (int i = 0; i < mat[qid].size(); i++) {
						if (connect[mat[qid][i]] == false) {
							connect[mat[qid][i]] = true;
							q.push(mat[qid][i]);
						}
					}
				}
				else if (!q.empty())
					q.push(-1);
			}
		}
	}
	if (K != 1) {
		printf("Error: %d components", K);
		return 0;
	}
	temp = BFS(1);
	answer = BFS(temp[0]);
	set<int> s;
	for (int i = 0; i < answer.size(); i++) s.insert(answer[i]);
	for (int i = 0; i < temp.size(); i++) s.insert(temp[i]);
	for (set<int>::iterator it=s.begin(); it != s.end(); it++)
		printf("%d\n", *it);
	return 0;
}