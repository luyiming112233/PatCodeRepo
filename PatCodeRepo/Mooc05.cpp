#include<cstdio>
#include<vector>
#include<stack>
using namespace std;

int M, N, K;

bool judge() {
	vector<int> v;
	stack<int> s;
	int n,num=1;
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		v.push_back(n);
	}
	for (int i = 0; i < v.size(); i++) {
		while (v[i] >= num) {
			s.push(num);
			num++;
		}
		if (s.size() > M)
			return false;
		if (s.top() == v[i]) s.pop();
		else return false;
	}
	return true;
}

int main() {
	scanf("%d %d %d", &M, &N, &K);
	for (int i = 0; i < K; i++) {
		if (judge()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}