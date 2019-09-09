#include<cstdio>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;

#define maxn 2510
#define slen 5

vector<string> s[maxn];

bool cmp(string a, string b) {
	return a < b;
}

int main() {
	int N, K, C, z;
	char name[slen];
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("\n%s %d", name, &C);
		for (int j = 0; j < C; j++) {
			scanf("%d", &z);
			s[z].push_back(name);
		}
	}
	for (int ki = 1; ki <= K; ki++) {
		printf("%d %d\n", ki, s[ki].size());
		sort(s[ki].begin(), s[ki].end());
		for (int it=0; it <s[ki].size(); it++)
			printf("%s\n", s[ki][it].c_str());
	}
	return 0;
}
