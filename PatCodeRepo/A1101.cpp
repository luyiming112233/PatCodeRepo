#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main() {
	vector<int> v1, v2;
	set<int> s;
	int N, num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		v1.push_back(num);
	}
	v2 = v1;
	sort(v2.begin(), v2.end());
	int maxV = 0;
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i] > maxV)
			maxV = v1[i];
		if (v1[i] == v2[i]  && v1[i]==maxV)
			s.insert(v1[i]);
	}
	printf("%d\n", s.size());
	bool first = true;
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		if (first) {
			printf("%d", *it);
			first = false;
		}
		else {
			printf(" %d", *it);
		}
	}
	printf("\n");
	return 0;
}