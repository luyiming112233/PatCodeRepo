#include<cstdio>

#define LL long long

int main() {
	LL N;
	LL a[12] = {0,1};
	LL jin = 1,sum=0;
	scanf("%lld", &N);
	if (N < 10) {
		printf("1");
		return 0;
	}


	for (int i = 2; i < 12; i++) {
		jin *= 10;
		a[i] = jin * 1 + 10 * a[i - 1];
	}
	LL v = 0,c;
	LL wei=1;
	while (wei <= N) {
		v++;
		wei *= 10;
	}
	wei /= 10;
	v--;
	while (wei > 0) {
		if (v == 0 && N!=0) {
			sum++;
			break;
		}
		c = N / wei;
		sum += (c*a[v]);
		N %= wei;
		//第v+1位 1的次数
		if(c==1)
    		sum += (N+1);
		else if(c!=0){
			sum += wei;
		}
		wei /= 10;
		v--;
	}
	printf("%lld", sum);
}