#include<cstdio>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

#define maxM 210
#define maxL 10010

int dp[maxM][maxL];

int main() {
	int N, M, L,num;
	fill(dp[0], dp[0] + maxL * maxM, 0);
	vector<int> a, b;
	a.push_back(-1), b.push_back(-1);
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &num);
		a.push_back(num);
	}
	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		scanf("%d", &num);
		b.push_back(num);
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= L; j++) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	printf("%d", dp[M][L]);
	return 0;
}