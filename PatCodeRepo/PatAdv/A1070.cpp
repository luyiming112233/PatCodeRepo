#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct moon {
	double w;
	double p;
	double b;
};

bool cmp(moon a, moon b) {
	return a.b > b.b;
}

int main() {
	int N;
	double D,sum=0;
	vector<moon> v;
	moon temp;
	scanf("%d %lf", &N, &D);
	for (int i = 0; i < N; i++) {
		scanf("%lf", &temp.w);
		v.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		scanf("%lf", &v[i].p);
		v[i].b = v[i].p / v[i].w;
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		if (D >= v[i].w) {
			D -= v[i].w;
			sum += v[i].p;
		}
		else {
			sum += (v[i].b*D);
			break;
		}
	}
	printf("%.2f", sum);
	return 0;
}