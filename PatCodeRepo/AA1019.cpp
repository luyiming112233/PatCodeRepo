#include<cstdio>
#include<vector>
using namespace std;

bool judge(vector<int> v) {
	int len = v.size();
	for (int i = 0; i < v.size() / 2; i++) 
		if (v[i] != v[len - 1 - i]) return false;
	return true;
}

int main() {
	int N, b;
	scanf("%d %d", &N, &b);
	if (N == 0) {
		printf("Yes\n0");
		return 0;
	}
	vector<int> v;
	while (N != 0) {
		v.push_back(N%b);
		N /= b;
	}
	if (judge(v)) printf("Yes\n");
	else printf("No\n");
	for (int i = v.size() - 1; i >= 0; i--) {
		if (i == v.size() - 1) printf("%d", v[i]);
		else printf(" %d", v[i]);
	}
	return 0;
}