#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

#define maxn 100010
#define bei 100

vector<int> v[maxn];
int retailers[maxn] = { 0 };

int main() {
	int N,num,sup,t;
	double price, R,sum=0,nR;
	scanf("%d", &N);
	scanf("%lf %lf", &price, &R);
	R /= 100;
	R += 1;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		if (num == 0) {
			scanf("%d", &sup);
			retailers[i] = sup;
		}
		else {
			for (int j = 0; j < num; j++) {
				scanf("%d", &sup);
				v[i].push_back(sup);
			}
		}
	}
	queue<int> q;
	q.push(0);
	q.push(-1);
	nR = 1.0;
	while (!q.empty()) {
		t = q.front();
		q.pop();
		if (t == -1) {
			nR *= R;
			if (q.empty())
				break;
			else
				q.push(-1);
		}
		else {
			if (v[t].size() == 0) {
				sum += nR * retailers[t];
			}
			else {
				for (int i = 0; i < v[t].size(); i++) {
					q.push(v[t][i]);
				}
			}
		}
	}
	sum *= price;
	printf("%.1f", sum);
	return 0;
}