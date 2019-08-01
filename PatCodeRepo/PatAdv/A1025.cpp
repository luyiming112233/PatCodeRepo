#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define INF -9999

struct test {
	long long id;
	int grade;
	int part;
	int srank;//小组排名
};

bool cmp(struct test a,struct test b) {
	if (a.grade != b.grade)
		return a.grade > b.grade;
	return a.id < b.id;
}

bool cmp2(struct test a, struct test b) {
	if (a.part != b.part)
		return a.part < b.part;
	if (a.grade != b.grade)
		return a.grade > b.grade;
	return a.id < b.id;
}

int main() {
	int N, K, ar[120] = { 0 }, rank = 0, grade = -1,start,num=0;
	vector<struct test>  v;
	test temp;
	scanf("%d", &N);
	for (int g = 1; g <= N; g++) {
		scanf("%d", &K);
		ar[g] = K;
		temp.part = g;
		for (int i = 0; i < K; i++) {
			scanf("%lld%d", &temp.id, &temp.grade);
			if (temp.grade < 0 || temp.grade>100 ||temp.id>=(long long)10000000000000 || temp.id <= (long long)999999999999) {
				temp.grade = INF;
			}
			else {
				num++;
			}
			v.push_back(temp);
		}
	}
	//计算小组排名
	sort(v.begin(), v.end(), cmp2);
	start = 0;
	for (int i = 1; i <= N; i++) {
		rank = 0;
		grade = -1;
		K = ar[i];
		for (int j = 0; j < K; j++) {
			if (v[start + j].grade != grade) {
				rank = j + 1;
				grade = v[start + j].grade;
			}
			v[start + j].srank = rank;
		}
		start += K;
	}
	//计算总体排名
	sort(v.begin(), v.end(), cmp);
	rank = 0;
	grade = -1;

	printf("%d\n", num);
	for (int i = 0; i < v.size(); i++) {
		//更新总排名
		if (v[i].grade != grade) {
			rank = i + 1;
			grade = v[i].grade;
		}
		if (v[i].grade == INF)
			continue;
		printf("%lld %d %d %d\n", v[i].id, rank, v[i].part, v[i].srank);
	}
	return 0;
}