#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

#define slen 10

struct school {
	string id;
	double TWS;
	int ITWS;
	int Ns;
	school() {
		TWS = 0;
		Ns = 0;
	}
};

bool cmp(school a, school b) {
	if (a.ITWS != b.ITWS)
		return a.ITWS > b.ITWS;
	if (a.Ns != b.Ns)
		return a.Ns < b.Ns;
	return a.id < b.id;
}

void lower(char* str) {
	for (int i = 0; i < slen; i++) {
		if (str[i] == '\0')
			break;
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 32;
		}
	}
}

int main() {
	vector<school> v;
	map<string, school> m;
	map<string, school>::iterator it;
	int N,grade;
	double fixG;
	char stuId[slen], sch[slen];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("\n%s %d %s", stuId, &grade, sch);
		lower(sch);
		switch (stuId[0]) {
		case 'B':
			fixG = 1.0*grade / 1.5;
			break;
		case 'A':
			fixG = 1.0*grade;
			break;
		case 'T':
			fixG = 1.5*grade;
			break;
		}
		it = m.find(sch);
		if (it == m.end()) {
			m[sch].TWS = fixG;
			m[sch].Ns = 1;
			m[sch].id = sch;
		}
		else {
			it->second.Ns++;
			it->second.TWS += fixG;
		}
	}
	for (it = m.begin(); it != m.end(); it++) {
		it->second.ITWS = it->second.TWS;
		v.push_back(it->second);
	}
	sort(v.begin(), v.end(), cmp);
	printf("%d\n", v.size());
	int rank = 0, preTWS = -1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].ITWS != preTWS) {
			preTWS = v[i].ITWS;
			rank = i + 1;
		}
		printf("%d %s %d %d\n", rank, v[i].id.c_str(), v[i].ITWS, v[i].Ns);
	}
	return 0;
}