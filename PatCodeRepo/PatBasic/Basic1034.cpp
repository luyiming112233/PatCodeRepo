#include<cstdio>

long long gcd(long long a,long long b) {
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	long long c = a % b;
	while(c!=0){
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

void print_num(long long a, long long b) {
	if (b < 0) {
		a = -a;
		b = -b;
	}
	//等于0
	if (a == 0) {
		printf("0");
	}
	//等于整数
	else if (a%b==0) {
		if (a < 0) 
			printf("(-%lld)", -a / b);
		else
			printf("%lld", a / b);
	}
	else {
		long long c = gcd(a, b);
		a /= c;
		b /= c;
		if (a < 0) {
			a = -a;
			printf("(-");
			if (a / b > 0)
				printf("%lld ", a / b);
			printf("%lld/%lld", a%b, b);
			printf(")");
		}
		else {
			if (a / b > 0)
				printf("%lld ", a / b);
			printf("%lld/%lld", a%b, b);
		}
	}
}

int main() {
	long long un1, un2, dn1, dn2,c, un3, dn3;
	bool z1 = false, z2 = false,fu=false;
	scanf("%lld/%lld %lld/%lld", &un1, &dn1, &un2, &dn2);
	if (un1%dn1 == 0)
		z1 = true;
	if (un2%dn2 == 0)
		z2 = true;
	//加法运算
	dn3 = dn1 * dn2;
	un3 = un1 * dn2 + un2 * dn1;
	print_num(un1, dn1);
	printf(" + ");
	print_num(un2, dn2);
	printf(" = ");
	print_num(un3,dn3);
	printf("\n");
	//减法运算
	un3 = un1 * dn2 - un2 * dn1;
	print_num(un1, dn1);
	printf(" - ");
	print_num(un2, dn2);
	printf(" = ");
	print_num(un3, dn3);
	printf("\n");
	//乘法运算
	un3 = un1 * un2;
	print_num(un1, dn1);
	printf(" * ");
	print_num(un2, dn2);
	printf(" = ");
	print_num(un3, dn3);
	printf("\n");
	//除法运算
	un3 = un1 * dn2;
	dn3 = un2 * dn1;
	print_num(un1, dn1);
	printf(" / ");
	print_num(un2, dn2);
	printf(" = ");
	if (dn3 != 0)
		print_num(un3, dn3);
	else
		printf("Inf");
	printf("\n");
	return 0;
}