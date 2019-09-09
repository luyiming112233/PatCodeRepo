#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define maxn 10010

struct user {
	int id,sum,grade[5],acnum;
	user() {
		sum = 0, acnum = 0;
		for (int i = 0; i < 5; i++) grade[i] = -2;
	}
}users[maxn];

bool cmp(user a,user b) {
	if (a.sum != b.sum)
		return a.sum > b.sum;
	if (a.acnum != b.acnum)
		return a.acnum > b.acnum;
	return a.id < b.id;
}

int main() {
	int N, K, M, id, tid, tgrade, ag[5];
	vector<user> v;
	scanf("%d %d %d", &N, &K, &M);
	for (int i = 0; i < K; i++)
		scanf("%d", &ag[i]);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &id, &tid, &tgrade);
		tid--;
		if (tgrade > ag[tid]) continue;
		if (users[id].grade[tid] < tgrade) users[id].grade[tid] = tgrade;
	}
	for (int i = 1; i <= N; i++) {
		bool flag = false;
		for (int t = 0; t < K; t++) {
			if (users[i].grade[t] >=0) {
				users[i].sum += users[i].grade[t];
				flag = true;
			}
			if (users[i].grade[t] == ag[t])
				users[i].acnum++;
		}
		users[i].id = i;
		if (flag) v.push_back(users[i]);
	}
	sort(v.begin(), v.end(), cmp);
	int rank = 1,gsum=-1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].sum != gsum) {
			gsum = v[i].sum;
			rank = i + 1;
		}
		printf("%d %05d %d", rank, v[i].id, v[i].sum);
		for (int j = 0; j < K; j++) {
			if (v[i].grade[j] == -2) printf(" -");
			else if (v[i].grade[j] == -1) printf(" 0");
			else printf(" %d", v[i].grade[j]);
		}
		printf("\n");
	}
	return 0;
}
