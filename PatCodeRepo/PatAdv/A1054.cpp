#include<cstdio>
#include<map>
using namespace std;

int main() {
	int M, N,num,max=0,nmax;
	map<int, int> m;
	map<int, int>::iterator it;
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &num);
			it = m.find(num);
			if (it == m.end()) {
				m[num] = 1;
			}
			else {
				it->second++;
			}
		}
	}
	for (it = m.begin(); it != m.end(); it++) {
		if (it->second > max) {
			max = it->second;
			nmax = it->first;
		}
	}
	printf("%d", nmax);
	return 0;
}