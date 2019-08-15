#include<cstdio>
#include<set>
#include<vector>
using namespace std;

#define maxn 1010

bool judge() {
	vector<int> v;
	set<int> add, sub,row;
	int N,num,nadd,nsub;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	for (int i = 0; i < v.size(); i++) {
		nadd = i + 1 + v[i];
		nsub = i + 1 - v[i];
		if (add.find(nadd) == add.end() && sub.find(nadd) == sub.end() &&row.find(v[i])==row.end()) {
			add.insert(nadd);
			sub.insert(nsub);
			row.insert(v[i]);
		}
		else {
			return false;
		}
	}
	return true;
}

int main() {
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		if (judge()) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}
