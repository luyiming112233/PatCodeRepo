#include<cstdio>
#include<queue>
using namespace std;

struct node {
	int a;
	friend bool operator < (node a, node b) {
		return a.a > b.a;
	}
	node(int aa) {
		a = aa;
	}
};

priority_queue<node> q;

int main() {
	for (int i = 0; i < 10; i++) {
		int n;
		scanf("%d", &n);
		q.push(node(n));
	}
	for (int i = 0; i < 10; i++) {
        printf("%d\n",q.top().a);
		q.pop();
	}
	return 0;
}