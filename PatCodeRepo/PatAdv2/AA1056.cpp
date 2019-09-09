#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct mice {
	int W, id, order, turn, rank;
};

bool cmp(mice a, mice b) {
	return a.order < b.order;
}

int main() {
	int Np, Ng,w,order;
	scanf("%d %d", &Np, &Ng);
	vector<mice> ms,v,win;
	mice temp;
	for (int i = 0; i < Np; i++) {
		scanf("%d", &w);
		temp.id = i;
		temp.W = w;
		ms.push_back(temp);
	}
	for (int i = 0; i < Np; i++) {
		scanf("%d", &order);
		ms[order].order = i;
	}
	v = ms;
	sort(v.begin(), v.end(), cmp);
	int turn = 0;
	while (true) {
		turn++;
		win.clear();
		if (v.size() == 1) {
			ms[v[0].id].turn = turn;
			break;
		}
		for (int g = 0; g < v.size(); g += Ng) {
			int index = -1, maxW = -10000;
			for (int i = g; i < v.size() && i < g + Ng; i++) {
				ms[v[i].id].turn = turn;
				if (v[i].W > maxW) {
					maxW = v[i].W;
					index = i;
				}
			}
			win.push_back(v[index]);
		}
		v = win;
	}
	int rank = 0,num=1;
	for (int t = turn; t > 0; t--) {
		rank=num;
		for (int i = 0; i < ms.size(); i++) 
			if (ms[i].turn == t) { 
				ms[i].rank = rank;
				num++;
			}
	}
	for (int i = 0; i < ms.size(); i++) {
		if (i == 0) printf("%d", ms[i].rank);
		else printf(" %d", ms[i].rank);
	}
	return 0;
}