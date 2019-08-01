#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

#define maxn 2510
#define slen 5

bool cmp(string a, string b) {
	return a < b;
}

int main() {
	int N, K,num,c;
	char name[slen];
	vector<string> v[maxn];
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%s", name);
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			scanf("%d", &c);
			v[c].push_back(name);
		}
	}
	for (int i = 1; i <= K; i++) {
		sort(v[i].begin(), v[i].end());
		printf("%d %d\n", i, v[i].size());
		for (int j = 0; j < v[i].size(); j++) {
			printf("%s\n", v[i][j].c_str());
		}
	}
	return 0;
}