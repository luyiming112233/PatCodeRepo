#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define LL long long int

bool cmp(LL a, LL b) {
	return a > b;
}

int main() {
	int Nc, Np;
	LL num,sum=0;
	vector<LL> zv1,zv2,fv1,fv2;
	scanf("%d", &Nc);
	for (int i = 0; i < Nc; i++) {
		scanf("%lld", &num);
		if (num > 0)
			zv1.push_back(num);
		else if (num < 0)
			fv1.push_back(num);
	}
	scanf("%d", &Np);
	for (int i = 0; i < Np; i++) {
		scanf("%lld", &num);
		if (num > 0)
			zv2.push_back(num);
		else if (num < 0)
			fv2.push_back(num);
	}
	sort(zv1.begin(), zv1.end(),cmp);
	sort(zv2.begin(), zv2.end(),cmp);
	sort(fv1.begin(), fv1.end(),cmp);
	sort(fv2.begin(), fv2.end(),cmp);
	int len = zv1.size();
	if (len > zv2.size())
		len = zv2.size();
	for (int i = 0; i < len; i++) {
		sum += (zv1[i] * zv2[i]);
	}
	len = fv1.size();
	if (len > fv2.size())
		len = fv2.size();
	for (int i = 0; i<len; i++) {
		sum += (fv1[fv1.size()-1-i] * fv2[fv2.size() - 1 - i]);
	}
	printf("%lld", sum);
	return 0;
}