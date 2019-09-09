#include<cstdio>

#define LL long long

bool judge() {
	LL num,temp,wei=0,a,b,z=1;
	scanf("%lld", &num);
	temp = num;
	while (temp != 0) {
		wei++;
		temp /= 10;
	}
	if (wei % 2 == 1)
		return false;
	for (int i = 0; i < wei / 2; i++)
		z *= 10;
	a = num / z;
	b = num % z;
	if (a*b == 0)
		return false;
	if (num % (a*b) == 0)
		return true;
	return false;
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		if (judge()) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}