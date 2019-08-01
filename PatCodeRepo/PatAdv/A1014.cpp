#include<cstdio>
#include<queue>
using namespace std;

#define maxn 1010

int N, M, K, Q, a[maxn] = { 0 };

struct wait_queue {
	int time;
	queue<int> q;
}wqs[20];

int time2num(int hh, int mm) {
	return hh * 60 + mm;
}

void print_time(int num,int num2) {
	if (num >= 1020) {
		printf("Sorry\n");
	}
	else {
		int hh, mm;
		hh = (num+num2) / 60;
		mm = (num+num2) % 60;
		printf("%02d:%02d\n", hh, mm);
	}
}

//返回最早的非空窗口
int get_quick_window() {
	int min = -1,mintime=10000000;
	for (int i = 0; i < N; i++) {
		if (!wqs[i].q.empty() && wqs[i].time+a[wqs[i].q.front()] < mintime) {
			min = i;
			mintime = wqs[i].time+ a[wqs[i].q.front()];
		}
	}
	return min;
}

int main(){
	int b[maxn] = { 0 },wait,win,cus,query;
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	for (int i = 1; i <= K; i++) {
		scanf("%d", &a[i]);
	}
	if (N*M >= K) {
		wait = K + 1;
	}
	else {
		wait = N * M + 1;
	}
	//初始化时间
	for (int i = 0; i < 20; i++) {
		wqs[i].time = time2num(8, 0);
	}
	//初始化队列
	for (int i = 1; i < wait; i++) {
		wqs[(i-1)%N].q.push(i);
	}
    //执行业务
	for (int i = 1; i <= K; i++) {
		win = get_quick_window();
		if (win == -1)
			break;
		cus = wqs[win].q.front();
		wqs[win].q.pop();
		b[cus] = wqs[win].time;
		wqs[win].time = wqs[win].time + a[cus];
		//下一个cus进入队伍
		if (wait <= K) {
			wqs[win].q.push(wait);
			wait++;
		}
	}
	for (int i = 0; i < Q; i++) {
		scanf("%d", &query);
		print_time(b[query],a[query]);
	}
	return 0;
}