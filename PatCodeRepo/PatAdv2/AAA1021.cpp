#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;

#define maxn 10010

vector<int> mat[maxn];
bool connect[maxn] = { false };

vector<int> BFS(int start) {
	queue<int> q;
	int qid;
	vector<int> temp, answer;
	q.push(start), q.push(-1);
	connect[start] = true;
	while (!q.empty()) {
		qid = q.front();
		q.pop();
		if (qid == -1) {
			answer = temp;
			temp.clear();
			if (!q.empty()) q.push(-1);
			else break;
		}
		else {
			temp.push_back(qid);
			for (int i = 0; i < mat[qid].size(); i++) {
				if (connect[mat[qid][i]] == false) {
					connect[mat[qid][i]] = true;
					q.push(mat[qid][i]);
				}
			}
		}
	}
	return answer;
}

int main() {
	int N, a, b, com=0;
	vector<int> v1, v2;
	scanf("%d", &N);
	for(int i=1;i<N;i++){
		scanf("%d %d", &a, &b);
		mat[a].push_back(b);
		mat[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		if (connect[i] == false) {
			com++;
			v1 = BFS(i);
		}
	}
	if (com > 1) printf("Error: %d components\n", com);
	else {
		fill(connect, connect + maxn, false);
		v2 = BFS(v1[0]);
		set<int> s;
		for (int i = 0; i < v1.size(); i++) s.insert(v1[i]);
		for (int i = 0; i < v2.size(); i++) s.insert(v2[i]);
		for (set<int>::iterator it = s.begin(); it != s.end(); it++)
			printf("%d\n", *it);
	}
	return 0;
}