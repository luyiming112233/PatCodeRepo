#include<cstdio>
#include<vector>
using namespace std;

int main() {
	int N;
	vector<int> v;
	char s, a;
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%c-%c", &s, &a);
			getchar();
			if (a == 'T')
				v.push_back(s - 'A' + 1);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		printf("%d", v[i]);
	}
	return 0;
}