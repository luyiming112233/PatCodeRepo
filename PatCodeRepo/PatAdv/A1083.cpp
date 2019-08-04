#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 12

struct stu {
	char name[maxn];
	char id[maxn];
	int grade;
};

bool cmp(stu a, stu b) {
	return a.grade> b.grade;
}

int main() {
	int N,g1,g2;
	stu temp;
	vector<stu> v;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s %s %d\n", temp.name, temp.id, &temp.grade);
		v.push_back(temp);
	}
	scanf("%d %d", &g1, &g2);
	sort(v.begin(), v.end(), cmp);
	int snum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].grade >= g1 && v[i].grade <= g2) {
			printf("%s %s\n", v[i].name, v[i].id);
			snum++;
		}
	}
	if (snum == 0)
		printf("NONE");
	return 0;
}
