#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int N, num;
	double len=0;
	vector<int> v;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	len = v[0];
	for (int i = 1; i < N; i++) {
		len += v[i];
		len /= 2;
	}
	int temp = len;
	printf("%d", temp);
	return 0;
}