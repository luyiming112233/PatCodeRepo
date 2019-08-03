// π”√BFS
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

#define maxn 100010

vector<int> v[maxn];

int main() {
	int N,root,par,turn=0,s;
	double P, R,nR;
	vector<int> an;
	queue<int> q;
	scanf("%d %lf %lf", &N,&P,&R);
	R = R / 100 + 1;
	for (int i = 0; i < N; i++) {
		scanf("%d", &par);
		if (par == -1) {
			root = i;
		}
		else {
			v[par].push_back(i);
		}
	}
	q.push(root);
	q.push(-1);
	nR = 1;
	while (true) {
		s = q.front();
		q.pop();
		if (s == -1) {
			if (q.empty())
				break;
			nR *= R;
			an.clear();
			q.push(-1);
		}
		else {
			an.push_back(s);
			for (int i = 0; i < v[s].size(); i++) {
				q.push(v[s][i]);
			}
		}
	}
	printf("%.2f %d", nR*P, an.size());
	return 0;
}