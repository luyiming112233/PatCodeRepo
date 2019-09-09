#include<cstdio>
#include<algorithm>
using namespace std;

#define maxn 100010

bool single[maxn] = { false };
int part[maxn];

int main() {
	fill(part, part + maxn, -1);
	int N, M,a,b,num=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		part[a] = b;
		part[b] = a;
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &a);
		if (part[a] == -1) {
			single[a] = true;
			num++;
		}
		else {
			if (single[part[a]]) {
				single[part[a]] = false;
				num--;
			}
			else {
				num++;
				single[a] = true;
			}
		}
	}
	bool first = true;
	printf("%d\n", num);
	for (int i = 0; i < maxn; i++) {
		if (single[i]) {
			if (first) {
				printf("%05d", i);
				first = false;
			}
			else {
				printf(" %05d", i);
			}
		}
	}
	return 0;
}