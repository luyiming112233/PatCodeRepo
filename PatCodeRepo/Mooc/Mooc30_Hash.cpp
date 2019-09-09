#include<cstdio>

#define maxn 200000
#define LL long long

struct phone{
	LL id;
	int num;
	phone() {
		id = -1;
		num = 0;
	}
}hash[maxn];

int find(LL pnum) {
	int key = pnum % maxn;
	int temp;
	for (int i = 0; i < maxn; i++) {
		temp = (key + i) % maxn;
		if (hash[temp].id == -1 || hash[temp].id == pnum)
			break;
	}
	return temp;
}

int main() {
	LL a, b;
	int N;
	int index;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld %lld", &a, &b);
		index = find(a);
		if (hash[index].id == -1) hash[index].id = a;
		hash[index].num++;
		index = find(b);
		if (hash[index].id == -1) hash[index].id = b;
		hash[index].num++;
	}
	LL pn;
	int maxN = -1,num=0;
	for (int i = 0; i < maxn; i++) {
		if (hash[i].id == -1) continue;
		if (hash[i].num > maxN) {
			pn = hash[i].id;
			maxN = hash[i].num;
			num = 1;
		}
		else if (hash[i].num == maxN) {
			num++;
			if (hash[i].id < pn) pn = hash[i].id < pn;
		}
	}
	if (num == 1) printf("%lld %d", pn, maxN);
	else printf("%lld %d %d", pn, maxN, num);
	return 0;
}