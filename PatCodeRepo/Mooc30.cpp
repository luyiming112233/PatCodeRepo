#include<cstdio>
#include<map>
using namespace std;

#define LL long long

int main() {
	map<LL, int> m;
	map<LL, int>::iterator it;
	int N;
	LL a, b;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld %lld", &a, &b);
		it = m.find(a);
		if (it == m.end()) m[a] = 1;
		else m[a]++;
		it = m.find(b);
		if (it == m.end()) m[b] = 1;
		else m[b]++;
	}
	int maxN = -1,num=0;
	LL phone;
	for (it = m.begin(); it != m.end(); it++) {
		if (it->second > maxN) {
			phone = it->first;
			maxN = it->second;
			num = 1;
		}
		else if (it->second == maxN)
			num++;
	}
	if(num==1) printf("%lld %d", phone, maxN);
	else printf("%lld %d %d", phone, maxN,num);
	return 0;
}