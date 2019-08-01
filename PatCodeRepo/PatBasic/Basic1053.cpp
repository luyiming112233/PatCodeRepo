#include<cstdio>

int main() {
	int N, D, day, kong;
	double th, v, p1 = 0, p2 = 0;
	scanf("%d %lf %d", &N, &th, &D);
	for (int i = 0; i < N; i++) {
		scanf("%d", &day);
		kong = 0;
		for (int j = 0; j < day; j++) {
			scanf("%lf", &v);
			if (v < th) {
				kong++;
			}
		}
		if (kong * 2 > day) {
			p1 += 1;
			if (day > D) {
				p2 += 1;
				p1 -= 1;
			}
		}
	}
	p1 = p1 * 100 / N;
	p2 = p2 * 100 / N;
	printf("%.1lf%% %.1lf%%\n", p1, p2);
	return 0;
}