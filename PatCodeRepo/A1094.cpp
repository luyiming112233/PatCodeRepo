#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define maxn 110

vector<int> v[maxn];

int main() {
	int N, M,id,k,kid,level=1,lnum=0,mlevel=0,mlnum=0;
	scanf("%d %d", &N, &M);
	queue<int> q;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &id, &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &kid);
			v[id].push_back(kid);
		}
	}
	q.push(1);
	q.push(-1);
	while (true) {
		id = q.front();
		q.pop();
		if (id == -1) {
			if (lnum > mlnum) {
				mlnum = lnum;
				mlevel = level;
			}
			level++;
			lnum = 0;
			if (!q.empty()) {
				q.push(-1);
			}
			else {
				break;
			}
		}
		else {
			lnum++;
			if (v[id].size() > 0) {
				for (int i = 0; i < v[id].size(); i++)
					q.push(v[id][i]);
			}
		}
	}
	printf("%d %d", mlnum, mlevel);
	return 0;
}