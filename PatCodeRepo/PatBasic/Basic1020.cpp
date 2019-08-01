#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct mcake {
	double weight, price;
	double k;
};

bool cmp(struct mcake a, struct mcake b) {
	return a.k > b.k;
}

int main() {
	int n, w;
	scanf("%d%d", &n, &w);
	vector<struct mcake> v;
	struct mcake temp;
	double sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lf", &temp.weight);
		v.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lf", &v[i].price);
		v[i].k = (double)v[i].price / (double)v[i].weight;
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++) {
		if (w >= v[i].weight) {
			w -= v[i].weight;
			sum += v[i].price;
		}
		else {
			sum += w * v[i].k;
			w = 0;
			break;
		}
	}
	printf("%.2f\n", sum);
	return 0;
}