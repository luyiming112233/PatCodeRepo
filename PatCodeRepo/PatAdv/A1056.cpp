#include<cstdio>
#include<vector>
using namespace std;

#define maxn 1010

int w[maxn] = { 0 };//权重
int t[maxn] = { 0 };//轮次
int index[maxn];    //次序
int nums[maxn] = {0};

vector<int> group;

void play(int turn) {
	int max = -1,maxp;
	for (int j = 0; j < group.size(); j++) {
		if (w[group[j]] > max) {
			max = w[group[j]];
			maxp = group[j];
		}
	}
	//给败者记录轮次
	for (int i = 0; i < group.size(); i++) {
		if (maxp != group[i]) {
			t[group[i]] = turn;
		}
	}
	group.clear();
}

int main() {
	int Np, Ng,turn,tnum,temp,maxp,max;
	scanf("%d%d\n", &Np, &Ng);
	for (int i = 0; i < Np; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 0; i < Np; i++) {
		scanf("%d", &temp);
		index[i] = temp; //第temp个是i号
	}
	turn = 0;
	tnum = 0;
	
	while (tnum < Np-1) {
		turn++;
		for (int i = 0; i < Np; i++) {
			if (t[index[i]] == 0) {
				group.push_back(index[i]);
				//组成一组
				if (group.size() == Ng) {
					tnum += (group.size() - 1);
					play(turn);

				}
			}
		}
		if (group.size() != 0) {
			tnum += (group.size() - 1);
			play(turn);
		}
	}
	for (int i = 0; i < Np; i++) {
		nums[t[i]]++;
	}
	for (int i = 2; i <= turn; i++) {
		nums[i] += nums[i - 1];
	}
	nums[0] = Np;
	for (int i = 0; i < Np; i++) {
		if (i != 0) {
			printf(" ");
		}
		printf("%d", Np + 1 - nums[t[i]]);
	}
	return 0;
}