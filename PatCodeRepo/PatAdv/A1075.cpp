#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxk 6
#define maxn 10010

int fgrade[maxk];
int N, K, M;

struct stu {
	int id;
	int grade[maxk];
	int num;
	int sum;
	bool ok;
	stu() {
		fill(grade, grade + maxk, -2);
		ok = false;
		num = 0;
		sum = 0;
	}
}stus[maxn];

void insert(int sid,int tid,int tgrade) {
	if (sid<1 || sid>N)
		return;
	if (tid<1 || tid>K)
		return;
	if (tgrade>fgrade[tid])
		return;
	if (tgrade > stus[sid].grade[tid]) {
		stus[sid].grade[tid] = tgrade;
	}
}

bool cmp(stu a, stu b) {
	if (a.sum != b.sum)
		return a.sum > b.sum;
	else if (a.num != b.num)
		return a.num > b.num;
	return a.id < b.id;
}

int main() {
	int sid,tid, tgrade;
	vector<stu> v;
	scanf("%d %d %d", &N, &K, &M);
	for (int i = 1; i <= K; i++) {
		scanf("%d", &fgrade[i]);
	}
	for (int i = 1; i <= N; i++) {
		stus[i].id = i;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &sid, &tid, &tgrade);
		insert(sid, tid, tgrade);
	}
	for (int i = 1; i <=N; i++) {
		for (int j = 1; j <= K; j++) {
			if (stus[i].grade[j] == fgrade[j]) {
				stus[i].num++;
			}
			if (stus[i].grade[j] >= 0) {
				stus[i].sum += stus[i].grade[j];
				stus[i].ok = true;
			}
		}
		if (stus[i].ok == true)
			v.push_back(stus[i]);
	}
	sort(v.begin(), v.end(), cmp);
	int rank = 0, score = -1000;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].sum != score) {
			score = v[i].sum;
			rank = i+1;
		}
		printf("%d %05d %d", rank, v[i].id, v[i].sum);
		for (int j = 1; j <= K; j++) {
			if (v[i].grade[j] == -2)
				printf(" -");
			else if (v[i].grade[j] == -1)
				printf(" 0");
			else
				printf(" %d", v[i].grade[j]);
		}
		printf("\n");
	}
	return 0;
}