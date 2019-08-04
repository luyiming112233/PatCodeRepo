#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	int N,s,num;
	vector<int> v,sv,t;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		sv.push_back(num);
	}
	t.assign(v.begin(), v.end());
	bool isPrint = false;
	for (int i = 1; i < N; i *= 2) {
		for (int j = 0; j + i <= N; j += i) {
			sort(t.begin() + j, t.begin() + j + i);
		}
		if (isPrint) {
			printf("Merge Sort\n");
			for (int i = 0; i < N; i++) {
				if (i == 0)
					printf("%d", t[i]);
				else {
					printf(" %d", t[i]);
				}
			}
			break;
		}
		isPrint = true;
		for (int i = 0; i < N; i++) {
			if (t[i] != sv[i]) {
				isPrint = false;
			}
		}
	}
	if (isPrint == false) {
		for (int i = 0; i < N - 1; i++) {
			if (sv[i] > sv[i + 1]) {
				s = i;
				break;
			}
		}
		t.assign(v.begin(), v.end());
		sort(t.begin(), t.begin() + s + 1);

		printf("Insertion Sort\n");
		sort(t.begin(), t.begin() + s + 2);
		for (int i = 0; i < N; i++) {
			if (i == 0)
				printf("%d", t[i]);
			else {
				printf(" %d", t[i]);
			}
		}
	}
	return 0;
}