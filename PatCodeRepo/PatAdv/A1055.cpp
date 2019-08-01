#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

#define slen 10

struct people {
	char name[slen];
	int age;
	int worth;
};

bool judge(people p) {
	int len;
	for (len = 0; len < slen; len++) {
		if (p.name[len] == '\0')
			break;
	}
	if (len > 8)
		return false;
	if (p.age < 0 || p.age>200)
		return false;
	if (p.worth<-1e6 || p.worth>1e6)
		return false;
	return true;
}

bool cmp(people a, people b) {
	if (a.worth != b.worth)
		return a.worth > b.worth;
	if (a.age != b.age)
		return a.age < b.age;
	return (string)a.name < (string)b.name;
}

int main() {
	int N, K;
	int num, min, max,fnum;
	people temp;
	vector<people> v;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%s %d %d", temp.name, &temp.age, &temp.worth);
		if (judge(temp))
			v.push_back(temp);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < K; i++) {
		scanf("%d%d%d", &num, &min, &max);
		printf("Case #%d:\n", i + 1);
		fnum = 0;
		for (int j = 0; j < v.size(); j++) {
			if (v[j].age >= min && v[j].age <= max) {
				fnum++;
				printf("%s %d %d\n", v[j].name, v[j].age, v[j].worth);
				if (fnum == num)
					break;
			}
		}
		if (fnum == 0)
			printf("None\n");
	}
	return 0;
}