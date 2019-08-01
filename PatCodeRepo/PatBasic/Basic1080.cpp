#include<cstdio>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

struct stu {
	char id[21];
	int Gp;
	int Gmt;
	int Gf;
	int G;
	bool n;
};

bool cmp(stu a, stu b) {
	if (a.G != b.G)
		return a.G > b.G;
	//int t = strcmp(a.id, b.id);
	return (string)a.id< (string)b.id;
}

#define ssize 50000

struct stu stus[ssize];

int main() {
	map<string, int> m;
	map<string, int>::iterator it;
	char tid[21];
	int P, M, N,tGp,tGmt,tGf,num=0;
	scanf("%d %d %d", &P, &M, &N);

	for (int i = 0; i < ssize; i++) {
		stus[i].G = -1;
		stus[i].Gf = -1;
		stus[i].Gmt = -1;
		stus[i].Gp = -1;
		stus[i].n = true;
	}
	//读入Gp成绩
	for (int i = 0; i < P; i++) {
		stu temp;
		scanf("%s %d", tid, &tGp);
		it = m.find(tid);
		//如果找不到，说明是新同学，添加信息
		if (it == m.end()) {
			m[tid] = num;
			strcpy(stus[num].id, tid);
			stus[num].Gp = tGp;
			if (tGp < 0 || tGp>900)
				stus[num].n = false;
			num++;
		}
		else {
			stus[it->second].Gp = tGp;
			if (tGp < 0 || tGp>900)
				stus[it->second].n = false;
		}
	}
	//读入Gmt成绩
	for (int i = 0; i < M; i++) {
		stu temp;
		scanf("%s %d", tid, &tGmt);
		it = m.find(tid);
		//如果找不到，说明是新同学，添加信息
		if (it == m.end()) {
			m[tid] = num;
			strcpy(stus[num].id, tid);
			stus[num].Gmt = tGmt;
			if (tGmt < 0 || tGmt>100)
				stus[num].n = false;
			num++;
		}
		else {
			stus[it->second].Gmt = tGmt;
			if (tGmt < 0 || tGmt>100)
				stus[it->second].n = false;
		}
	}
	//读入Gf成绩
	for (int i = 0; i < N; i++) {
		stu temp;
		scanf("%s %d", tid, &tGf);
		it = m.find(tid);
		//如果找不到，说明是新同学，添加信息
		if (it == m.end()) {
			m[tid] = num;
			strcpy(stus[num].id, tid);
			stus[num].Gf = tGf;
			if (tGf < 0 || tGf>100)
				stus[num].n = false;
			num++;
		}
		else {
			stus[it->second].Gf = tGf;
			if (tGf < 0 || tGf>100)
				stus[it->second].n = false;
		}
	}
	vector<stu> v;
	int mtemp;
	//开始计算获得合格证的学生
	for (int i = 0; i < num; i++) {
		if (stus[i].Gp < 200 || stus[i].n==false)
			continue;
		if (stus[i].Gf > stus[i].Gmt)
			stus[i].G = stus[i].Gf;
		else {
			mtemp = stus[i].Gmt * 4 + stus[i].Gf * 6;
			if (mtemp % 10 >= 5)
				mtemp += 10;
			stus[i].G = mtemp / 10;
		}
		if (stus[i].G >= 60)
			v.push_back(stus[i]);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		printf("%s %d %d %d %d\n", v[i].id, v[i].Gp, v[i].Gmt, v[i].Gf, v[i].G);
	}
	return 0;
}