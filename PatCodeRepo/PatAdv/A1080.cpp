#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

#define cnum 5

struct stu {
	int Ge, Gi, Gf, rank,id;
	int choices[cnum];
};

struct school {
	int lrank, quota;
	set<int> stuId;
};

int N, M, K;
vector<school> sc;
vector<stu> v;

bool cmp(stu sa, stu sb) {
	if (sa.Gf != sb.Gf)
		return sa.Gf > sb.Gf;
	return sa.Ge > sb.Ge;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	school schtemp;
	stu a;
	for (int i = 0; i < M; i++) {
		scanf("%d", &schtemp.quota);
		sc.push_back(schtemp);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a.Ge, &a.Gi);
		a.Gf = (a.Ge + a.Gi) / 2;
		a.id = i;
		for (int j = 0; j < K; j++) 
			scanf("%d", &a.choices[j]);
		v.push_back(a);
	}
	sort(v.begin(), v.end(), cmp);
	int rank = 0, TGf = 10000, TGe = 10000;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].Gf < TGf) {
			rank = i+1;
			TGf = v[i].Gf;
			TGe = v[i].Ge;
		}
		else if (v[i].Gf == TGf && v[i].Ge < TGe) {
			rank = i + 1;
			TGf = v[i].Gf;
			TGe = v[i].Ge;
		}
		v[i].rank = rank;
	}
	bool flag;
	for (int i = 0; i < v.size(); i++) {
		flag = false;
		for (int j = 0; j < K; j++) {
			int ch = v[i].choices[j];
			if (sc[ch].stuId.size() < sc[ch].quota) {
				sc[ch].stuId.insert(v[i].id);
				sc[ch].lrank = v[i].rank;
				flag = true;
				break;
			}
			else if (sc[ch].lrank == v[i].rank) {
				sc[ch].stuId.insert(v[i].id);
				flag = true;
				break;
			}
		}
		if (flag) continue;
	}
	for (int i = 0; i < sc.size(); i++) {
		bool first = true;
		for (set<int>::iterator it = sc[i].stuId.begin(); it != sc[i].stuId.end(); it++) {
		    if(first){
				printf("%d", *it);
				first = false;
			}else{
				printf(" %d", *it);
			}
		}
		printf("\n");
	}
	return 0;
}