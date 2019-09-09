#include<cstdio>
#include<set>
#include<vector>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;

#define maxn 25

int main() {
	vector<string> v;
	set<string> s;
	char str[maxn];
	int M, N, S;
	scanf("%d %d %d\n", &M, &N, &S);
	for (int i = 0; i < M; i++) {
		cin.getline(str, maxn);
		v.push_back(str);
	}
	S -= 1;
	while (S < M) {
		if (s.find(v[S]) == s.end()) {
			s.insert(v[S]);
			printf("%s\n", v[S].c_str());
			S += N;
		}
		else {
			S++;
		}
	}
	if (s.size() == 0) {
		printf("Keep going...");
	}
	return 0;
}