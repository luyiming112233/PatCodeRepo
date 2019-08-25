#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> coins,answer,temp;
bool flag = false;

void DFS(int i,int v) {
	if (v == 0) {
		answer = temp;
		flag = true;
		return;
	}
	if (!flag &&i < coins.size() && coins[i]<=v ) {
		temp.push_back(coins[i]);
		v -= coins[i];
		DFS(i + 1, v);
		v += coins[i];
		temp.pop_back();
		if (!flag) {
			DFS(i + 1, v);
		}
	}
}

int main() {
	int N, M, num,sum=0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		if (num <= M) {
			sum += num;
			coins.push_back(num);
		}
	}
	if (sum < num ) {
		printf("No Solution");
		return 0;
	}
	sort(coins.begin(), coins.end());
	DFS(0, M);
	if (flag) {
		for (int i = 0; i < answer.size(); i++) {
			if (i == 0) printf("%d", answer[i]);
			else printf(" %d", answer[i]);
		}
	}
	else
		printf("No Solution");
	return 0;
}