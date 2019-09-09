#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxN 10010
#define maxL 110

int dp[maxN][maxL];
int mat[maxN][maxL];

int main() {
	int N, M,num,sum=0;
	fill(dp[0], dp[0] + maxN * maxL, 0);
	fill(mat[0], mat[0] + maxN * maxL, -1);
	vector<int> coins,answer;
	scanf("%d %d", &N, &M);
	coins.push_back(M + 1);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		sum += num;
		coins.push_back(num);
	}
	sort(coins.begin(), coins.end());
	reverse(coins.begin(), coins.end());
	if (sum < M) {
		printf("No Solution\n");
		return 0;
	}
	for (int i = 1; i <= N; i++) {
	    for (int v = 1; v <= M; v++) {
			if (coins[i] <= v) {
				dp[i][v] = max(dp[i - 1][v], dp[i - 1][v - coins[i]] + coins[i]);
				if (dp[i][v] == dp[i - 1][v - coins[i]] + coins[i]) mat[i][v] = coins[i];
				else mat[i][v] = 0;
			}
			else {
				dp[i][v] = dp[i - 1][v];
				mat[i][v] = 0;
			}
		}
	}
	if (dp[N][M] == M) {
		int m = M, c = N;
		while (mat[c][m] != -1) {
			if (mat[c][m] == 0) {
				c--;
			}
			else {
				answer.push_back(coins[c]);
				m -= coins[c];
				c--;
			}
		}
		for (int i = 0; i <answer.size(); i++) {
			if (i == 0)
				printf("%d", answer[i]);
			else
				printf(" %d", answer[i]);
		}
	}else
		printf("No Solution\n");
	return 0;	
}