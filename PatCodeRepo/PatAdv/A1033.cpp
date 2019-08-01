#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 510

struct station {
	double price;
	int dis;
};

struct p {
	double dis, 
		Cdis,//距离容量
		Mdis;//剩余可行驶距离
}tp;

bool cmp(station a, station b) {
	return a.dis < b.dis;
}



int main() {
	double Cm, D, Da;
	int N;
	double staDis[maxn] = { 0 };
	int start, select;
	vector<station> v;
	station temp;
	scanf("%lf %lf %lf %d", &Cm, &D, &Da, &N);
	for (int i = 0; i < N; i++) {
		scanf("%lf %d", &temp.price, &temp.dis);
		v.push_back(temp);
	}
	temp.dis = D;
	temp.price = 0;
	v.push_back(temp);
	sort(v.begin(), v.end(), cmp);
	tp.dis = 0;
	tp.Cdis = Cm * Da;
	tp.Mdis = 0;
	start = 0;
	double minprice;//最低价
	bool havenext,flag;
	int tt;
	while (tp.dis < D) {
		select = start;
		minprice = v[start].price;
		havenext = false;
		flag = false;
		tt = start + 1;
		for (int i = start+1; i <= N; i++) {
			if (v[i].dis > tp.dis + tp.Cdis) {
				break;
			}
			else {
				havenext = true;
				if (v[i].price < v[tt].price)
					tt = i;
			}
			if (flag == false && minprice >= v[i].price) {
				select = i;
				minprice = v[i].price;
				flag = true;
			}
		}
		//无法到达
		if (havenext==false) {
			break;
		}
		if (start == select) {
			staDis[start] = tp.Cdis-tp.Mdis;
			//计算到达下一站的剩余油量
			tp.Mdis = tp.Cdis-(v[tt].dis- v[start].dis);
			start = tt;
			tp.dis = v[start].dis;
		}
		else {
			//计算加油量
			staDis[start] = v[select].dis - tp.dis - tp.Mdis;
			start = select;
			tp.dis = v[start].dis;
			tp.Mdis = 0;
		}
	}
	if(v[0].dis!=0)
		printf("The maximum travel distance = %.2lf", (double)0);
	else if (tp.dis< D) {
		printf("The maximum travel distance = %.2lf", tp.dis + tp.Cdis);
	}
	else {
		double sum = 0;
		for (int i = 0; i < N; i++) {
			sum += staDis[i] * v[i].price;
		}
		printf("%.2lf", sum / Da);
	}
}