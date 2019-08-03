#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define LL long long

int main() {
	int N, p,maxnum=0,start,end;
	LL num,temp;
	vector<LL> v;
	scanf("%d %d", &N, &p);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	start = 0, end = 0;
	while (end < N) {
		temp = v[start] * p;
		if (temp >= v[end]) {
			end++;
			if (end - start > maxnum) {
				maxnum = end - start;
			}
		}
		else {
			start++;
		}
	}
	printf("%d", maxnum);
	return 0;
}