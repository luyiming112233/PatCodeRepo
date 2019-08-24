#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define LL long long

struct stu {
	LL id;
	int grade;
	int lnum, lrank;
};

bool cmp(stu a, stu b) {
	if (a.grade != b.grade)
		return a.grade > b.grade;
	return a.id < b.id;
}

int main() {
	int N, K, tg, trank;
	vector<stu> temp, stus;
	stu ts;
	scanf("%d", &N);
	for (int ni = 1; ni <= N; ni++) {
		ts.lnum = ni;
		temp.clear();
		scanf("%d", &K);
		for (int i = 0; i < K; i++) {
			scanf("%lld %d", &ts.id, &ts.grade);
			temp.push_back(ts);
		}
		sort(temp.begin(), temp.end(), cmp);
		tg = -1, trank = 0;
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i].grade != tg) {
				trank = i + 1;
				tg = temp[i].grade;
			}
			temp[i].lrank = trank;
			stus.push_back(temp[i]);
		}
	}
	sort(stus.begin(), stus.end(), cmp);
	tg = -1, trank = 0;
	printf("%d\n", stus.size());
	for (int i = 0; i < stus.size(); i++) {
		if (stus[i].grade != tg) {
			trank = i + 1;
			tg = stus[i].grade;
		}
		printf("%013lld %d %d %d\n", stus[i].id, trank, stus[i].lnum, stus[i].lrank);
	}
	return 0;
}