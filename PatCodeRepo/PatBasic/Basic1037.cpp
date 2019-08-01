#include<cstdio>

int getsum(int g,int s,int k) {
	return g * 17 * 29 + s * 29 + k;
}

int main() {
	int g1, s1, k1, ss1, g2, s2, k2, ss2, g3, s3, k3, ss3;
	scanf("%d.%d.%d", &g1, &s1, &k1);
	scanf("%d.%d.%d", &g2, &s2, &k2);
	ss1 = getsum(g1, s1, k1);
	ss2 = getsum(g2, s2, k2);
	ss3 = ss2 - ss1;
	if (ss3 < 0) {
		printf("-");
		ss3 = -ss3;
	}
	k3 = ss3 % 29;
	ss3 /= 29;
	s3 = ss3 % 17;
	g3 = ss3 / 17;
	printf("%d.%d.%d", g3, s3, k3);
	return 0;
}
