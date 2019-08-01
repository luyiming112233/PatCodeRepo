#include<cstdio>

int main() {
	int t1, t2, s, hh, mm, ss;
	scanf("%d%d", &t1, &t2);
	s = t2 - t1;
	if (s % 100 >= 50) {
		s = s / 100 + 1;
	}
	else {
		s = s / 100;
	}
	ss = s % 60;
	mm = (s / 60) % 60;
	hh = (s / 3600);
	printf("%02d:%02d:%02d\n", hh, mm, ss);
	return 0;
}