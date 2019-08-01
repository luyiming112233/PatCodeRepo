#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 110

int N, K;
int windows[maxn];

struct process {
	int come;
	double pro;
};

int time2num(int hh,int mm,int ss) {
	return 3600 * hh + 60 * mm + ss;
}

bool judgetime(int hh, int mm, int ss) {
	if (hh >= 0 && hh <= 23 && mm >= 0 && mm < 60 && ss >= 0 && ss < 60 && time2num(hh,mm,ss)<=61200) {
		return true;
	}
	return false;
}

//返回最快的一个窗口
int get_quick_win() {
	int id = -1, mintime = 10000000;
	for (int i = 0; i < K; i++) {
		if (windows[i] < mintime ){//&&windows[i] <= 61200) {
			id = i;
			mintime = windows[i];
		}
	}
	return id;
}

int wait_time(int peo,int win) {
	if (peo > win)
		return 0;
	else
		return win - peo;
}

bool cmp(struct process a, struct process b) {
	if(a.come!=b.come)
    	return a.come < b.come;
	return a.pro < b.pro;
}

int main() {
	vector<struct process> v;
	int num=0,hh,mm,ss,sumtime=0,wid;
	double pro;
	process temp;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d:%d:%d %lf", &hh, &mm, &ss, &pro);
		if (judgetime(hh, mm, ss)) {
			num++;
			temp.come = time2num(hh, mm, ss);
			temp.pro = pro;
			v.push_back(temp);
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < K; i++) {
		windows[i] = 8 * 3600;
	}

	bool free = true;
	for (int i = 0; i < v.size(); i++) {
		// 查看是否有空窗口,取一个id
		if (free) {
			wid = get_quick_win();
			//表示所有的窗口都结束了
			if (wid == -1) {
				free = false;
			}
		}
		if (wid == -1) {
			sumtime += wait_time(v[i].come, 61200);
		}
		else {
			sumtime += wait_time(v[i].come, windows[wid]);
			if(windows[wid]> v[i].come)
			    windows[wid] += v[i].pro*60;
			else
				windows[wid]= v[i].come+ v[i].pro * 60;
		}
	}
	double wait_min = 1.0*sumtime / 60 / num;
	printf("%.1lf\n", wait_min);
	return 0;
}