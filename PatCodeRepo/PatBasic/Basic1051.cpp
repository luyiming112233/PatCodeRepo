#include<cstdio>
#include<cmath>

int main() {
	double r1, p1, r2, p2, a1, b1, a2, b2,a3,b3;
	scanf("%lf%lf%lf%lf", &r1, &p1, &r2, &p2);
	a1 = r1 * cos(p1);
	b1 = r1 * sin(p1);
	a2 = r2 * cos(p2);
	b2 = r2 * sin(p2);
	a3 = a1 * a2 - b1 * b2;
	b3 = a1 * b2 + a2 * b1;
	//误差校正，-0.005～0的数字保留两位输出为-0.00
	if (a3 > -0.005  && a3 < 0) {
		a3 = -a3;
	}
	printf("%.2lf",a3);
	if (b3 > -0.005  && b3 < 0) {
		b3 = -b3;
	}
	if (b3 >= 0) {
		printf("+");
	}
	printf("%.2lfi\n", b3);
	return 0;
}