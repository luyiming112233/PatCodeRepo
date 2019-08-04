#include<cstdio>

#define LL long long

LL getB(LL a, LL b) {
	LL c;
	if (a == 0)
		return b;
	if (b == 0)
		return a;
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

int getDeno(LL a, LL b, LL c) {
	LL ta = a / c,tb = b/c;
	return ta * tb*c;
}

int main() {
	int N;
	LL a, b,sa=0,sb=1,tb,td,z1,z2;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld/%lld", &a, &b);
		tb = getB(b, sb);
		td = getDeno(b, sb, tb);
		z1 = td / sb;
		z2 = td / b;
		sa = sa * z1 + a * z2;
		sb = td;
		
		tb = getB(sa, sb);
		sa /= tb;
		sb /= tb;

	}
	if (sa < 0) {
		printf("-");
		sa = -sa;
	}
	bool both = false;
	if (sa == 0)
		printf("0");
	else {
		if (sa >= sb) {
			printf("%lld", sa / sb);
			both = true;
		}
		if (sa%sb != 0) {
			if (both)
				printf(" ");
			printf("%lld/%lld", sa%sb, sb);
		}
	}
	return 0;
}


