#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;

#define maxn 1010

int num[maxn];
int M, N, K;

bool judge() {
	int start = 1;
	stack<int> s;
	for (int i = 0; i < N; i++) {
		while (num[i]>=start) {
			s.push(start);
			start++;
		}
		if (s.size() > M)
			return false;
		if (s.top() != num[i])
			return false;
		s.pop();
	}
	return true;
}

int main() {
	scanf("%d %d %d", &M, &N, &K);
	for (int i = 0; i < K; i++){
		for (int j = 0; j < N; j++) {
			scanf("%d", &num[j]);
		}
		if (judge() == true) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}