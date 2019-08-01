#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

#define maxn 1010

vector<int> v[maxn];
int status[maxn];

int main() {
	int N, L,a,b,fn,follow;
	scanf("%d%d", &N, &L);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &fn);
		for (int j = 0; j < fn; j++) {
			scanf("%d", &follow);
			v[follow].push_back(i);
		}
	}
	int qn, query,sq,weibo;
	scanf("%d", &qn);
	for (int i = 0; i < qn; i++) {
		queue<int> q;
		sq = 0;
		fill(status, status + maxn, 0);
	    scanf("%d", &query);
		q.push(query);
		q.push(-1);
		//sq++;
		status[query] = 1;
		for (int t = 0; t < L; t++) {
			while (true) {
				weibo = q.front();
				q.pop();
				if (weibo == -1) {
					q.push(-1);
					break;
				}
				else {
					for (int qi = 0; qi < v[weibo].size(); qi++) {
						if (status[v[weibo][qi]] == 0) {
							q.push(v[weibo][qi]);
							status[v[weibo][qi]] = 1;
							sq++;
						}
					}
				}
			}
		}
		printf("%d\n", sq);
	}
	return 0;
}