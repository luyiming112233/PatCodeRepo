#include<cstdio>
#include<map>
using namespace std;

#define dsize 1000010

double a[dsize] = { 0 };
int main() {
	int K,tnum,k=0;
	double tv;
	map<int, double> m1, m2, answer;
	map<int, double>::iterator it1,it2,itan;
	
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %lf", &tnum,&tv);
		m1[tnum] = tv;
	}

	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %lf", &tnum, &tv);
		m2[tnum] = tv;
	}

	for (it1 = m1.begin(); it1 != m1.end(); it1++) {
		for (it2 = m2.begin(); it2 != m2.end(); it2++) {
			tnum = it1->first + it2->first;
			tv = it1->second*it2->second;
			itan = answer.find(tnum);
			if (itan != answer.end()) {
				itan->second += tv;
			}
			else
				answer[tnum] = tv;
		}
	}
	
	for (itan = answer.begin(); itan != answer.end(); itan++) {
		if (itan->second != (double)0) {
			a[itan->first] = itan->second;
			k++;
		}
	}
	printf("%d", k);
	for (int i = dsize-1; i >= 0; i--) {
		if (a[i] != (double)0)
			printf(" %d %.1lf", i, a[i]);
	}
	return 0;
}