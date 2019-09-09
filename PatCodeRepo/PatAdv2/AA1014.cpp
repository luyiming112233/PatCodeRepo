#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define START 480
#define END 1020
#define maxK 1010

struct window {
	int time;
	queue<int> q;
	window() {
		time = START;
	}
};

vector<window> win;
vector<int> customer, query;
int finish[maxK] = { 0 };
int N, M, K, Q;
int Cindex = 0;

void addQueue() {
	if (Cindex == K) return;
	int minLen = 1000000, wIndex = 0;
	for (int i = 0; i < win.size(); i++) {
		if (win[i].q.size() < minLen) {
			minLen = win[i].q.size();
			wIndex = i;
		}
	}
	win[wIndex].q.push(Cindex);
	Cindex++;
}

void service() {
	int minTime = 10000000, wIndex = 0;
	for (int i = 0; i < win.size(); i++) {
		if (win[i].q.size() != 0 && win[i].time+customer[win[i].q.front()] < minTime) {
			minTime = win[i].time + customer[win[i].q.front()];
			wIndex = i;
		}
	}
	int cid = win[wIndex].q.front();
	win[wIndex].q.pop();
	if (win[wIndex].time < END) {
		finish[cid] = win[wIndex].time + customer[cid];
		win[wIndex].time = finish[cid];
	}
	else 
		finish[cid] = -1;
}

void printTime(int num) {
	if (num == -1) printf("Sorry\n");
	else {
		int hh = num / 60;
		int mm = num % 60;
		printf("%02d:%02d\n",hh,mm);
	}
}

int main() {
	scanf("%d %d %d %d", &N, &M, &K, &Q);
	int time,que;
	window temp;
	for (int i = 0; i < N; i++) 
		win.push_back(temp);
	for (int i = 0; i < K; i++) {
		scanf("%d", &time);
		customer.push_back(time);
	}
	for (int i = 0; i < Q; i++) {
		scanf("%d", &que);
		query.push_back(que);
	}
	for (int i = 0; i < N*M; i++) 
		addQueue();
	for (int i = 0; i < K; i++) {
		service();
		addQueue();
	}
	for (int i = 0; i < query.size(); i++) 
		printTime(finish[query[i]-1]);
	return 0;
}