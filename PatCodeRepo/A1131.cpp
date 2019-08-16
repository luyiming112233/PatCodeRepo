#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

#define maxn 10010
#define INF 1000000

struct edge {
	int next;
	int line;
};

bool connect[maxn];
int minDis[maxn];
vector<edge> v[maxn];
vector<int> tpath[maxn];
vector<int> tempAnswer;
vector<int> answer;
set<int> s;
set<int>::iterator it;
int trans;

void update() {
	vector<int> rpath = tempAnswer;
	reverse(rpath.begin(), rpath.end());
	int num = 0, line = -1;
	for (int i = 0; i < rpath.size()-1; i++) {
		int index = rpath[i], next = rpath[i + 1];
		for (int j = 0; j < v[index].size(); j++) {
			if (v[index][j].next == next) {
				if (v[index][j].line != line) {
					line = v[index][j].line;
					num++;
				}
				break;
			}
		}
	}
	if (num < trans) {
		trans = num;
		answer = rpath;
	}
}

void DFS(int index,int start,int minS) {
	if (tempAnswer.size() > minS)
		return;
	if (index == start) {
		tempAnswer.push_back(index);
		update();
		tempAnswer.pop_back();
	}
	else{
		tempAnswer.push_back(index);
		for (int i = 0; i < tpath[index].size(); i++) {
			DFS(tpath[index][i], start,minS);
		}
		tempAnswer.pop_back();
	}
}

void display() {
	int num = 0, line = -1,start;
	for (int i = 0; i < answer.size() - 1; i++) {
		int index = answer[i], next = answer[i + 1];
		for (int j = 0; j < v[index].size(); j++) {
			if (v[index][j].next == next) {
				if (v[index][j].line != line) {
					if (line == -1) {
						line = v[index][j].line;
						start = index;
					}
					else {
						printf("Take Line#%d from %d to %d.\n", line, start, index);
						line = v[index][j].line;
						start = index;
					}	
				}
				break;
			}
		}
	}
	printf("Take Line#%d from %d to %d.\n", line, start, answer.back());
}

int main() {
	int N,M,a,b,K,start,end,index,minD;
	scanf("%d", &N);
	edge tedge;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &M);
		scanf("%d", &b);
		tedge.line = i;
		s.insert(b);
		for (int j = 1; j < M; j++) {
			a = b;
			scanf("%d", &b);
			tedge.next = b;
			v[a].push_back(tedge);
			tedge.next = a;
			v[b].push_back(tedge);
			s.insert(b);
		}
	}
	scanf("%d", &K);
	for (int bi = 0; bi < K; bi++) {
		fill(connect, connect + maxn, false);
		fill(minDis, minDis + maxn, INF);
		trans = INF;
		answer.clear();
		tempAnswer.clear();
		for (it = s.begin(); it != s.end(); it++) {
			tpath[*it].clear();
		}
		scanf("%d %d", &start, &end);
		if (start == end) {
			printf("0\n");
			continue;
		}
		minDis[start] = 0;
		for (int step = 0; step < maxn; step++) {
			index = -1;
			minD = INF;
			for (it=s.begin(); it!=s.end(); it++) {
				if (minDis[*it] < minD && connect[*it]==false) {
					minD = minDis[*it];
					index = *it;
				}
			}
			if (index == -1)
				break;
			connect[index] = true;
			for (int i = 0; i < v[index].size(); i++) {
				if (minDis[v[index][i].next] > minDis[index] + 1 && connect[v[index][i].next]==false) {
					minDis[v[index][i].next] = minDis[index] + 1;
					tpath[v[index][i].next].clear();
					tpath[v[index][i].next].push_back(index);
				}
				else if (minDis[v[index][i].next] == minDis[index] + 1 && connect[v[index][i].next] == false) {
					tpath[v[index][i].next].push_back(index);
				}
			}
		}
		printf("%d\n", minDis[end]);
		DFS(end, start,minDis[end]);
		display();
	}
	return 0;
}