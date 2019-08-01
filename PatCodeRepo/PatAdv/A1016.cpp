#include<vector>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
#include<cstdio>
using namespace std;

double h[24];

struct time {
	int dd, hh, mm;
	bool on;
};

bool cmp(struct time a,struct time b) {
	if (a.dd != b.dd)
		return a.dd < b.dd;
	else if (a.hh != b.hh)
		return a.hh < b.hh;
	else
		return a.mm < b.mm;
}

double cal_mon(struct time a, struct time b) {
	printf("%02d:%02d:%02d %02d:%02d:%02d", a.dd, a.hh, a.mm, b.dd, b.hh, b.mm);
	int diff = b.dd * 24 * 60 + b.hh * 60 + b.mm - (a.dd * 24 * 60 + a.hh * 60 + a.mm);
	int cdiff = diff,more_min;
	double money = 0;
	while (diff>0) {
		more_min = 60 - a.mm;
		if (more_min >= diff) {
			more_min = diff;
		}
		diff -= more_min;
		money += (1.0*more_min)*h[a.hh];
		a.mm = (a.mm + more_min);
		if (a.mm >= 60) {
			a.mm %= 60;
			a.hh++;
			if (a.hh >= 24) {
				a.hh %= 24;
				a.dd++;
			}
		}
	}
	money /= 100;
	printf(" %d $%.2f\n", cdiff, money);
	return money;
}

int main() {
	map<string, vector<struct time> > m;
	map<string, vector<struct time> >::iterator it;
	int N,month,s,on;
	double sum;
	char str[20],name[25];
	bool pairon;
	struct time temp;
	for (int i = 0; i < 24; i++)
		scanf("%lf", &h[i]);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s %d:%d:%d:%d %s", name, &month, &temp.dd, &temp.hh, &temp.mm, &str);
		if (strcmp(str, "on-line") == 0) {
			temp.on = true;
		}
		else
			temp.on = false;
		it = m.find(name);
		if (it == m.end()) {
			vector<struct time> tv;
			tv.push_back(temp);
			m[name] = tv;
		}
		else {
			it->second.push_back(temp);
		}
	}
	//¿ªÊ¼Êä³ö
	for (it = m.begin(); it != m.end(); it++) {
		bool ll = true;
		s = 0;
		on = 0;
		pairon = false;
		sum = 0;
		sort(it->second.begin(), it->second.end(), cmp);
		for (s = 0; s < (it->second.size()); s++) {
			if (it->second[s].on == true) {
				pairon = true;
				on = s;
			}
			else if(it->second[s].on == false && pairon ==true) {
				if (ll) {
					cout << it->first;
					printf(" %02d\n", month);
					ll = false;
				}
				pairon = false;
				sum += cal_mon(it->second[on], it->second[s]);
			}
		}
		if(ll==false)
    		printf("Total amount: $%.2f\n", sum);
	}
	return 0;
}