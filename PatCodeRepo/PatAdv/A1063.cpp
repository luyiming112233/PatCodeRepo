#include<cstdio>
#include<set>
using namespace std;

#define maxn 55

int main() {
	set<int> s[maxn];
	set<int>::iterator sit,it2;
	int N,M,K,num,a,b,Nc,Nt;
	double answer;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &M);
		for (int j = 0; j < M; j++) {
			scanf("%d", &num);
			s[i].insert(num);
		}
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &a, &b);
		Nc = 0, Nt = 0;
		Nt = s[a].size();
		for (it2 = s[b].begin(); it2 != s[b].end(); it2++) {
			if (s[a].find(*it2) != s[a].end()) {
				Nc++;
			}
			else {
				Nt++;
			}
		}
		answer = (100.0*Nc) / Nt;
		printf("%.1f%%\n", answer);
	}
	return 0;
}