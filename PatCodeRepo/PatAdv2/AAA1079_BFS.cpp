#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define maxn 100010

vector<int> mat[maxn];
int N, W[maxn] = { 0 };
double P, r, sum = 0;

int main() {
	scanf("%d %lf %lf", &N, &P, &r);
	r = (r / 100) + 1;
	int K, num;
	for (int ni = 0; ni < N; ni++) {
		scanf("%d", &K);
		if (K == 0) {
			scanf("%d", &W[ni]);
		}
		else {
			for (int i = 0; i < K; i++) {
				scanf("%d", &num);
				mat[ni].push_back(num);
			}
		}
	}
	queue<int> q;
	q.push(0), q.push(-1);
	int qid;
	//如果有环 有向 需要connect
	while (!q.empty()) {
		qid = q.front();
		q.pop();
		if (qid == -1) {
			P *= r;
			if (!q.empty()) q.push(-1);
			else break;
		}
		else {
			sum += (W[qid] * P);
			for (int i = 0; i < mat[qid].size(); i++)
				q.push(mat[qid][i]);
		}
	}
	printf("%.1f", sum);
	return 0;
}