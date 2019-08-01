#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N,a,b;
	scanf("%d", &N);
	vector<int> v;
	while (true) {
		v.clear();
		a = 0, b = 0;
		for (int i = 0; i < 4; i++) {
			v.push_back(N % 10);
			N /= 10;
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < 4; i++) {
			a = a * 10 + v[i];
			b = b * 10 + v[3 - i];
		}
		N = b - a;
		printf("%04d - %04d = %04d\n", b, a, N);
		if (N == 0 || N == 6174)
			break;
	}
	return 0;
}