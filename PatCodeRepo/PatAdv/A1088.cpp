#include<cstdio>

#define LL long long

LL getC(LL a,LL b) {
	if (a == 0)
		return b;
	LL c;
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (a < b) {
		c = a;
		a = b;
		b = c;
	}
	while (true) {
		c = a % b;
		if (c == 0)
			break;
		a = b;
		b = c;
	}
	return b;
}

void printNum(LL a,LL b) {
	if (b < 0) {
		a = -a;
		b = -b;
	}
	if (a == 0)
		printf("0");
	else {
		bool fu = false;
		LL c = getC(a, b);
		a /= c;
		b /= c;
		if (a < 0) {
			a = -a;
			fu = true;
		}
		if (fu) {
			printf("(-");
		}
		if (a / b > 0) {
			printf("%lld", a / b);
		}
		if (a%b != 0) {
			if (a / b > 0)
				printf(" ");
			printf("%lld/%lld", a%b, b);
		}
		if (fu) {
			printf(")");
		}
	}
}

void add(LL a1, LL b1, LL a2, LL b2) {
	LL a3 = a1 * b2 + a2 * b1, b3 = b1 * b2;
	printNum(a1, b1);
	printf(" + ");
	printNum(a2, b2);
	printf(" = ");
	printNum(a3, b3);
	printf("\n");
}

void jian(LL a1, LL b1, LL a2, LL b2) {
	LL a3 = a1 * b2 - a2 * b1, b3 = b1 * b2;
	printNum(a1, b1);
	printf(" - ");
	printNum(a2, b2);
	printf(" = ");
	printNum(a3, b3);
	printf("\n");
}

void cheng(LL a1, LL b1, LL a2, LL b2) {
	LL a3 = a1 * a2, b3 = b1 * b2;
	printNum(a1, b1);
	printf(" * ");
	printNum(a2, b2);
	printf(" = ");
	printNum(a3, b3);
	printf("\n");
}

void chu(LL a1, LL b1, LL a2, LL b2) {
	LL a3 = a1 * b2, b3 = b1 * a2;
	printNum(a1, b1);
	printf(" / ");
	printNum(a2, b2);
	printf(" = ");
	if (b3 != 0)
		printNum(a3, b3);
	else
		printf("Inf");
	printf("\n");
}

int main() {
	LL a1, b1, a2, b2,c1,c2,z1,z2;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	c1 = getC(a1, b1);
	a1 /= c1;
	b1 /= c1;
	c2 = getC(a2, b2);
	a2 /= c2;
	b2 /= c2;
	add(a1, b1, a2, b2);
	jian(a1, b1, a2, b2);
	cheng(a1, b1, a2, b2);
	chu(a1, b1, a2, b2);
	return 0;
}