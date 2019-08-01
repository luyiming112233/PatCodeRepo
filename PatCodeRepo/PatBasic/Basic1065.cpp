#include<cstdio>
#include<set>
using namespace std;
int main() {
	int p[100010] = { -1 };
	int N,a,b,M;
	set<int> s;
	set<int>::iterator it;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &a, &b);
		p[a] = b;
		p[b] = a;
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &a);
		it = s.find(p[a]);
		if (it == s.end()) {
			s.insert(a);
		}
		else {
			s.erase(it);
		}
	}
	printf("%d\n", s.size());
	bool f = true;
	for (it = s.begin(); it != s.end(); it++) {
		if (f) {
			f = false;
			printf("%05d", *it);
		}
		else {
			printf(" %05d", *it);
		}
	}
	//printf("\n");
	return 0;
}