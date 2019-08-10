#include<cstdio>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;

#define slen 10

struct peo {
	int height;
	char name[slen];
};

bool cmp(peo a, peo b) {
	if (a.height != b.height)
		return a.height > b.height;
	return (string)a.name < (string)b.name;
}

bool first;
void printName(char *name) {
	if (first == true) {
		printf("%s", name);
		first = false;
	}
	else {
		printf(" %s", name);
	}
}

int main() {
	int N, K,rk,frk,s;
	vector<peo> v;
	peo temp;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%s %d", temp.name, &temp.height);
		if (temp.height >= 30 && temp.height <= 300)
			v.push_back(temp);
	}
	sort(v.begin(), v.end(), cmp);
	rk = N / K;
	frk = rk + N % K;
	s = 0;
	int ss;
	for (int bi = 0; bi < K; bi++) {
		first = true;
		if (bi == 0) {
			if (frk % 2 == 1) {
				ss = frk - 2;
			}
			else {
				ss = frk - 1;
			}
			for (int i = ss; i>0; i-=2) {
				printName(v[i + s].name);
			}
			for (int i = 0; i < frk; i += 2) {
				printName(v[i + s].name);
			}
			s += frk;
		}
		else {
			if (rk % 2 == 1) {
				ss = rk - 2;
			}
			else {
				ss = rk - 1;
			}
			for (int i = ss; i > 0; i -= 2) {
				printName(v[i + s].name);
			}
			for (int i = 0; i < rk; i += 2) {
				printName(v[i + s].name);
			}
			s += rk;
		}
		printf("\n");
	}

	return 0;
}