#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define maxn 100010

vector<int> v[maxn];

int main() {
	int N,num,kid,cheep=0,su;
	double P, R;
	scanf("%d %lf %lf", &N, &P, &R);
	R = R / 100 + 1;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			scanf("%d", &kid);
			v[i].push_back(kid);
		}
	}
	queue<int> q;
	q.push(0);
	q.push(-1);
	while (!q.empty()) {
		su = q.front();
		q.pop();
		if (su == -1) {
			if (cheep != 0)
				break;
			if (!q.empty()) {
				P *= R;
				q.push(-1);
			}
		}
		else {
			if (v[su].size() == 0) {
				cheep++;
			}
			else {
				for (int i = 0; i < v[su].size(); i++) {
					q.push(v[su][i]);
				}
			}
		}
	}
	printf("%.4lf %d", P, cheep);
	return 0;
}