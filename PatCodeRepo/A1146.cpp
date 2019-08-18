#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define maxn 1010

vector<int> v[maxn];

int indgree[maxn];
int tdgree[maxn];
int N, M, K, a, b;

bool test() {
	fill(tdgree, tdgree + maxn, 0);
	vector<int> points;
	int temp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		points.push_back(temp);
	}
	for (int i = 0; i < points.size(); i++) {
		temp = points[i];
		if (tdgree[temp] != indgree[temp])
			return false;
		for (int j = 0; j < v[temp].size(); j++)
			tdgree[v[temp][j]]++;
	}
	return true;
}

int main() {
	fill(indgree, indgree + maxn, 0);
	vector<int> answer;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		indgree[b]++;
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		if (!test())
			answer.push_back(i);
	}
	for (int i = 0; i < answer.size(); i++) {
		if (i == 0)
			printf("%d", answer[i]);
		else 
			printf(" %d", answer[i]);
	}
	return 0;
}