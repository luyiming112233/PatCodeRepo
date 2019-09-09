#include<cstdio>
#include<set>
#include<unordered_map>
#include<string>
#include<string.h>
using namespace std;

#define slen 5

int main() {
	unordered_map<string, set<int> > m;
	unordered_map<string, set<int> >::iterator mit;
	set<int>::iterator sit;
	set<int> temp;
	char name[slen];
	int N, K,id,Ni;
	scanf("%d %d", &N, &K);
	for (int ki = 0; ki < K; ki++) {
		scanf("%d %d\n", &id, &Ni);
		for (int i = 0; i < Ni; i++) {
			scanf("%s", name);
			mit = m.find(name);
			if (mit == m.end())
				m[name] = temp;
			m[name].insert(id);
		}
	}
	scanf("\n");
	for (int si = 0; si < N; si++) {
		scanf("%s", name);
		printf("%s", name);
		mit = m.find(name);
		if (mit == m.end())
			printf(" 0\n");
		else {
			printf(" %d", mit->second.size());
			for (sit = mit->second.begin(); sit != mit->second.end(); sit++)
				printf(" %d", *sit);
			printf("\n");
		}
	}
	return 0;
}