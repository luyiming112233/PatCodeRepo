//问题：会员可以选择多张桌子时，先选择VIP
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxt 110

struct player {
	int arrive;//达到时间
	int ptime;//开始玩耍时间
	int wtime;//玩耍总时间
	int tag;
	bool flag;
};

struct table
{	
	int time;
	int tag;
	int num;
};

int N, K, M;
struct table tables[maxt];

int time2num(int hh, int mm, int ss) {
	return hh * 3600 + mm * 60 + ss;
}

void print_time(int num) {
	int hh = num / 3600;
	int mm = num % 3600 / 60;
	int ss = num % 60;
	printf("%02d:%02d:%02d", hh, mm, ss);
}

bool cmp(player a, player b) {
	return a.arrive < b.arrive;
}

int getTable() {
	int t, min = 1000000000;
	for (int i = 1; i <= K; i++) {
		if (tables[i].time < min) {
			min = tables[i].time;
			t = i;
		}
	}
	if (min >= 75600)
		return -1;
	else
		return t;
}

int main() {
	int hh, mm, ss,at,vp,t,rank,vrank,pp,lm,www;
	vector<player> v;
	player temp;
	temp.flag = false;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &www, &temp.tag);
		//超过2小时按2小时计算
		if (www > 120)
			www = 120;
		temp.wtime = www * 60;
		at = time2num(hh, mm, ss);
		//过滤无效数据
		if (at >= 28800 && at <= 75600 &&www<=120 &&www>=0) {
			temp.arrive = at;
			v.push_back(temp);
		}
	}
	scanf("%d %d", &K, &M);
	for (int i = 1; i <= K; i++) {
		tables[i].time = 28800;
		tables[i].tag = 0;
		tables[i].num = 0;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &vp);
		tables[vp].tag = 1;
	}
	sort(v.begin(), v.end(), cmp);
	rank = 0;
	vrank = 0;
	bool vip = false,hasvip = true;
	while (true) {
		t = getTable();
		vip = false;
		if (t == -1)
			break;
		//VIP桌，先看有没有VIP
		if (tables[t].tag == 1 && vrank<v.size()) {
			for (vrank = rank; vrank < v.size(); vrank++) {
				//找到最前面的一个vip，判断时间,
				//测试点8，flag=false
				if (v[vrank].tag == 1 && v[vrank].flag==false) {
					if (v[vrank].arrive <= tables[t].time) {
						vip = true;
						break;
					}
					else {
						break;
					}
				}
			}
		}
		if (vip) {
			tables[t].num++;
			v[vrank].flag = true;
			v[vrank].ptime = tables[t].time;
			tables[t].time = v[vrank].ptime + v[vrank].wtime;
			pp = vrank;
		}
		else {
			//找到下一个到达的人
			for (; rank < v.size(); rank++) {
				if (v[rank].flag == false)
					break;
			}
			//所有人完成
			if (rank == v.size())
				break;
			v[rank].flag = true;
			if (v[rank].arrive < tables[t].time)
				v[rank].ptime = tables[t].time;
			else {
				v[rank].ptime = v[rank].arrive;
			}
			tables[t].time = v[rank].ptime + v[rank].wtime;
			tables[t].num++;
			pp = rank;
		}
		print_time(v[pp].arrive);
		printf(" ");
		print_time(v[pp].ptime);
		lm = (v[pp].ptime - v[pp].arrive) / 6;
		if (lm % 10 >= 5)
			lm += 10;
		lm /= 10;
		printf(" %d\n", lm);
	}
	for (int i = 1; i <= K; i++) {
		if (i == 1)
			printf("%d", tables[i].num);
		else {
			printf(" %d", tables[i].num);
		}
	}
	printf("\n");
	return 0;
}
