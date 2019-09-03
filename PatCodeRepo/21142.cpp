#include<cstdio>
#include<queue>
using namespace std;

#define LL long long

priority_queue<LL, vector<LL>, greater<LL> > q;

int main() {
	int N, num;
	LL a, b, sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		q.push(num);
	}
	while (q.size() != 1) {
		a = q.top(), q.pop();
		b = q.top(), q.pop();
		a = a + b;
		sum += a;
		q.push(a);
	}
	printf("%lld", sum);
	return 0;
}