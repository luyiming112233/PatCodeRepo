#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

#define slen 25

struct stu {
	string id;
	int Gp, Gm, Gf, G;
	stu() {
		Gp = -1, Gm = -1, Gf = -1;
	}
};

bool cmp(stu a, stu b) {
	if (a.G != b.G)
		return a.G > b.G;
	return a.id < b.id;
}

int main() {
	int P, M, N,Gp,Gm,Gf,temp;
	char str[slen];
	vector<stu> v;
	map<string, stu> m;
	map<string, stu>::iterator it;
	scanf("%d %d %d", &P, &M, &N);
	for (int i = 0; i < P; i++) {
		scanf("\n%s %d", str, &Gp);
		if (Gp >= 200 && Gp <= 900) {
			m[str].Gp = Gp;
		}
	}
	for (int i = 0; i < M; i++) {
		scanf("\n%s %d", str, &Gm);
		it = m.find(str);
		if (it != m.end() && Gm >= 0 && Gm <= 100) {
			m[str].Gm = Gm;
		}
	}
	for (int i = 0; i < N; i++) {
		scanf("\n%s %d", str, &Gf);
		it = m.find(str);
		if (it != m.end() && Gf >= 0 && Gf <= 100) {
			m[str].Gf = Gf;
		}
	}
	for (it = m.begin(); it != m.end(); it++) {
		it->second.id = it->first;
		if (it->second.Gf > it->second.Gm) {
			it->second.G = it->second.Gf;
		}
		else {
			temp = it->second.Gf * 6 + it->second.Gm * 4;
			if (temp % 10 >= 5)
				temp += 10;
			it->second.G = temp / 10;
		}
		if (it->second.G >= 60)
			v.push_back(it->second);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		printf("%s %d %d %d %d\n", v[i].id.c_str(), v[i].Gp, v[i].Gm, v[i].Gf, v[i].G);
	}
	return 0;
}