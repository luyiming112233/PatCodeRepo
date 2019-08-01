#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
using namespace std;

struct stu {
	char sid[7];
	int C, M, E, A, Crank, Mrank, Erank, Arank;
};

bool cmpC(stu a,stu b) {
	return a.C > b.C;
}

bool cmpM(stu a, stu b) {
	return a.M > b.M;
}

bool cmpE(stu a, stu b) {
	return a.E > b.E;
}

bool cmpA(stu a, stu b) {
	return a.A > b.A;
}

void print_best_rank(stu s) {
	if (s.Arank<=s.Crank && s.Arank <= s.Mrank && s.Arank <= s.Erank) {
		printf("%d A\n",s.Arank);
	}
	else if (s.Crank <= s.Mrank && s.Crank <= s.Erank) {
		printf("%d C\n", s.Crank);
	}
	else if (s.Mrank <= s.Erank) {
		printf("%d M\n", s.Mrank);
	}
	else {
		printf("%d E\n", s.Erank);
	}
}

int main() {
	int N, M,num=0,tave,rank,lgrade;
	vector<stu> stus,stus_2;
	map<string,int> m;
	map<string, int>::iterator it;
	stu temp;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s %d %d %d", &temp.sid, &temp.C, &temp.M, &temp.E);
		tave = temp.C + temp.M + temp.E;
		//四舍五入
		if (tave % 3 == 2)
			tave++;
		temp.A = tave / 3;
		m[temp.sid] = num;
		stus.push_back(temp);
		stus_2.push_back(temp);
		num++;
	}
	//C
	lgrade = -1;
	rank = 1;
	sort(stus.begin(), stus.end(), cmpC);
	for (int i = 0; i < stus.size(); i++) {
		it = m.find(stus[i].sid);
		if (stus[i].C == lgrade) {
			stus_2[it->second].Crank = rank;
		}
		else {
			rank = i + 1;
			lgrade = stus[i].C;
			stus_2[it->second].Crank = rank;
		}
	}
	//M
	lgrade = -1;
	rank = 1;
	sort(stus.begin(), stus.end(), cmpM);
	for (int i = 0; i < stus.size(); i++) {
		it = m.find(stus[i].sid);
		if (stus[i].M == lgrade) {
			stus_2[it->second].Mrank = rank;
		}
		else {
			rank = i + 1;
			lgrade = stus[i].M;
			stus_2[it->second].Mrank = rank;
		}
	}
	//E
	lgrade = -1;
	rank = 1;
	sort(stus.begin(), stus.end(), cmpE);
	for (int i = 0; i < stus.size(); i++) {
		it = m.find(stus[i].sid);
		if (stus[i].E == lgrade) {
			stus_2[it->second].Erank = rank;
		}
		else {
			rank = i + 1;
			lgrade = stus[i].E;
			stus_2[it->second].Erank = rank;
		}
	}
	//A
	lgrade = -1;
	rank = 1;
	sort(stus.begin(), stus.end(), cmpA);
	for (int i = 0; i < stus.size(); i++) {
		it = m.find(stus[i].sid);
		if (stus[i].A == lgrade) {
			stus_2[it->second].Arank = rank;
		}
		else {
			rank = i + 1;
			lgrade = stus[i].A;
			stus_2[it->second].Arank = rank;
		}
	}
	//开始查找
	char search[7];
	for (int i = 0; i < M; i++) {
		scanf("%s", search);
		it = m.find(search);
		if (it != m.end()) {
			print_best_rank(stus_2[it->second]);
		}else{
			printf("N/A\n");
		}
	}
	return 0;
}