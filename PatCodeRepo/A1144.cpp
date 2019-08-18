#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N,num;
	vector<int> v;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		if (num > 0)
			v.push_back(num);
	}
	sort(v.begin(), v.end());
	int now = 1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == now) {
			now++;
		}
		else if (v[i] > now)
			break;
	}
	printf("%d", now);
	return 0;
}
