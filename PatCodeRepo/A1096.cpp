#include<cstdio>
#include<vector>
#include<math.h>
using namespace std;

int main() {
	int N,tn;
	vector<int> temp, v;
	scanf("%d", &N);
	tn = N;
	int sqr = (int)sqrt(N);
	for (int i = 2; i <= sqr; i++) {
		if (N%i == 0) {
			tn = N;
			temp.clear();
			int ti = i;
			while (tn%ti == 0 && ti <= N) {
				temp.push_back(ti);
				tn /= ti;
				ti++;
			}
			if (temp.size() > v.size()) {
				v = temp;
			}
		}
	}
	if(v.size()==0)
		v.push_back(N);
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) {
		if (i == 0) {
			printf("%d", v[i]);
		}
		else {
			printf("*%d", v[i]);
		}
	}
	return 0;
}