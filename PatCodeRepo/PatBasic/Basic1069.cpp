#include<cstdio>
#include<set>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

int main() {
	int M, N, S;
	set<string> s;
	vector<string> v;
	set<string>::iterator it;
	char str[25];
	scanf("%d %d %d\n", &M, &N, &S);
	for (int i = 0; i < M; i++) {
		scanf("%s", str);
		v.push_back(str);
	}
	int start = S - 1;
	while (start < M) {
		it = s.find(v[start]);
		if (it == s.end()) {
			printf("%s\n", v[start].c_str());
			s.insert(v[start]);
			start += N;
		}
		else {
			start++;
		}
	}
	if (s.size() == 0)
		printf("Keep going...\n");
	return 0;
}