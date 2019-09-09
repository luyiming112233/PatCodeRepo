#include<cstdio>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<unordered_map>
using namespace std;

#define slen 25

struct stu {
	string str;
	char L;
	string sitenum, date;
	int grade;
}stutemp;

struct G {
	string id;
	int num;
	G(string ID, int NUM) {
		id = ID, num = NUM;
	}
};

unordered_map<string, vector<stu> > Msite, Mdate;
unordered_map<string, vector<stu> >::iterator sit;
unordered_map<char, vector<stu> > ML;
unordered_map<char, vector<stu> >::iterator cit;

bool cmp(stu a, stu b) {
	if (a.grade != b.grade) return a.grade > b.grade;
	return a.str < b.str;
}

bool cmp2(G g1, G g2) {
	if (g1.num != g2.num) return g1.num > g2.num;
	return g1.id < g2.id;
}

void T1(char *str) {
	char L = str[0];
	cit = ML.find(L);
	if (cit == ML.end() || cit->second.size() == 0) {
		printf("NA\n");
		return;
	}
	sort(cit->second.begin(), cit->second.end(), cmp);
	for (int i = 0; i < cit->second.size(); i++)
		printf("%s %d\n", cit->second[i].str.c_str(), cit->second[i].grade);
}

void T2(char *str) {
	int sum = 0;
	sit = Msite.find(str);
	if (sit == Msite.end() || sit->second.size() == 0) {
		printf("NA\n");
		return;
	}
	for (int i = 0; i < sit->second.size(); i++)
		sum += sit->second[i].grade;
	printf("%d %d\n", sit->second.size(), sum);
}

void T3(char *str) {
	sit = Mdate.find(str);
	if (sit == Mdate.end() || sit->second.size() == 0) {
		printf("NA\n");
		return;
	}
	unordered_map<string, int> MG;
	vector<G> vG;
	for (int i = 0; i < sit->second.size(); i++) {
		if (MG.find(sit->second[i].sitenum) == MG.end()) MG[sit->second[i].sitenum] = 0;
		MG[sit->second[i].sitenum]++;
	}
	for (unordered_map<string, int>::iterator it = MG.begin(); it != MG.end(); it++) {
		vG.push_back(G(it->first, it->second));
	}
	sort(vG.begin(), vG.end(), cmp2);
	for (int i = 0; i < vG.size(); i++)
		printf("%s %d\n", vG[i].id.c_str(), vG[i].num);
}

int main() {
	int N, M, type;
	char str[slen], Csite[slen], Cdate[slen];
	Csite[3] = '\0', Cdate[6] = '\0';
	vector<stu> vtemp;
	scanf("%d %d", &N, &M);
	for (int ni = 0; ni < N; ni++) {
		scanf("\n%s %d", str, &stutemp.grade);
		if (stutemp.grade < 0 || stutemp.grade>100) continue;
		stutemp.L = str[0];
		Csite[0] = str[1], Csite[1] = str[2], Csite[2] = str[3];
		Cdate[0] = str[4], Cdate[1] = str[5], Cdate[2] = str[6], Cdate[3] = str[7], Cdate[4] = str[8], Cdate[5] = str[9];
		stutemp.sitenum = Csite, stutemp.str = str, stutemp.date = Cdate;
		sit = Msite.find(Csite);
		if (sit == Msite.end()) {
			Msite[Csite] = vtemp;
			Msite[Csite].push_back(stutemp);
		}
		else sit->second.push_back(stutemp);
		sit = Mdate.find(Cdate);
		if (sit == Mdate.end()) {
			Mdate[Cdate] = vtemp;
			Mdate[Cdate].push_back(stutemp);
		}
		else sit->second.push_back(stutemp);
		cit = ML.find(stutemp.L);
		if (cit == ML.end()) {
			ML[stutemp.L] = vtemp;
			ML[stutemp.L].push_back(stutemp);
		}
		else cit->second.push_back(stutemp);
	}
	for (int mi = 1; mi <= M; mi++) {
		scanf("%d %s", &type, str);
		printf("Case %d: %d %s\n", mi, type, str);
		switch (type) {
		case 1:T1(str); break;
		case 2:T2(str); break;
		case 3:T3(str); break;
		}
	}
	return 0;
}