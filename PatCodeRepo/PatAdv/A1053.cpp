#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 110

vector<int> mat[maxn];
vector < vector<int> > answer;
vector<int> answerId;
vector<int> tv;
int nums[maxn] = { 0 };
int N, M, S;

void DFS(int id,int sum) {
	sum += nums[id];
	tv.push_back(nums[id]);
	if (mat[id].size() != 0) {
		for (int i = 0; i < mat[id].size(); i++) {
			DFS(mat[id][i], sum);
		}
	}else if (sum == S) {
		answer.push_back(tv);
	}
	sum -= nums[id];
	tv.pop_back();
}

bool cmp(vector<int> a, vector<int> b) {
	int minLen = a.size();
	if (minLen > b.size())
		minLen = b.size();
	for (int i = 0; i < minLen; i++) {
		if (a[i] != b[i]) {
			return a[i] > b[i];
		}
	}
	return false;
}

void printV(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		if (i == 0)
			printf("%d", v[i]);
		else
			printf(" %d", v[i]);
	}
	printf("\n");
}

int main() {
	scanf("%d%d%d", &N, &M, &S);
	int tid, k, kid;
	for (int i = 0; i < N; i++) {
		scanf("%d", &nums[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &tid,&k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &kid);
			mat[tid].push_back(kid);
		}
	}
	DFS(0, 0);
	sort(answer.begin(), answer.end(), cmp);
	for (int i = 0; i < answer.size(); i++) {
		printV(answer[i]);
	}
	return 0;
}