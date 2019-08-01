#include<cstdio>
#include<vector>
using namespace std;

#define maxn 100010

int a[maxn] = {0};

int main() {
	int N,num;
	vector<int> v;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		v.push_back(num);
		a[num]++;
	}
	int s;
	for (s = 0; s < v.size(); s++) {
		if (a[v[s]] == 1) {
			printf("%d", v[s]);
			break;
		}
	}
	if (s == v.size())
		printf("None");
	return 0;
}