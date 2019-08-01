#include<cstdio>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#define maxn 2010
#define slen 5

struct phone {
	char name[slen];
	int time;
}plen[maxn];

int typeID = 0,pid=0;

int getPid() {
	return pid++;
}

int mat[maxn][maxn];

bool cmp(phone a,phone b) {
	return (string)a.name < (string)b.name;
}

int main() {
	int N, K,tv,ia,ib,num,clu_num;
	bool connect[maxn];
	fill(connect, connect + maxn, false);
	fill(mat[0], mat[0] + maxn * maxn, 0);
	map<string, int> m;
	map<string, int>::iterator it;
	char sa[slen], sb[slen];
	phone temp;
	vector <phone> answer;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%s %s %d", sa, sb, &tv);
		it = m.find(sa);
		if (it != m.end()) {
			ia = it->second;
		}
		else {
			ia = getPid();
			m[sa] = ia;
			strcpy(plen[ia].name, sa);
			plen[ia].time = 0;
		}
		it = m.find(sb);
		if (it != m.end()) {
			ib = it->second;
		}
		else {
			ib = getPid();
			m[sb] = ib;
			strcpy(plen[ib].name, sb);
			plen[ib].time = 0;
		}
		mat[ia][ib] += tv;
		mat[ib][ia] += tv;
	}
	num = N;
	clu_num = 0;
	vector<int> vp;
	queue<int> qp;
	int qid;
	while (num != 0) {
		int clu_l = 0;
		for (int i = 0; i < N; i++) {
			if (connect[i] == false) {
				qp.push(i);
				connect[i] = true;
				break;
			}
		}
		while (!qp.empty()) {
			qid = qp.front();
			qp.pop();
			num--;
			vp.push_back(qid);
			for (int i = 0; i < N; i++) {
				if (connect[i] == false && mat[i][qid] > 0) {
					connect[i] = true;
					qp.push(i);
				}
				if (mat[i][qid] > 0) {
					plen[i].time += mat[i][qid];
					plen[qid].time += mat[i][qid];
					clu_l += mat[i][qid];
				}
			}
		}
		//开始计算结果
		int vid = 0, timemax = 0;
		for (int i = 0; i < vp.size(); i++) {
			if (timemax < plen[vp[i]].time) {
				timemax = plen[vp[i]].time;
				vid = vp[i];
			}
		}
		strcpy(temp.name, plen[vid].name);
		temp.time = vp.size();
		if(temp.time>2 && clu_l/2>K)
    		answer.push_back(temp);
		vp.clear();
	}
	sort(answer.begin(), answer.end(), cmp);
	printf("%d\n", answer.size());
	for (int i = 0; i < answer.size(); i++) {
		printf("%s %d\n", answer[i].name, answer[i].time);
	}

	return 0;
}