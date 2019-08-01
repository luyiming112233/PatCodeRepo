#include<cstdio>

int main(){
	int N,a=0,b,sum;
	scanf("%d", &N);
	sum = N * 5;
	for (int i = 0; i < N; i++) {
		scanf("%d", &b);
		if (a > b) {
			sum += (a - b) * 4;
		}
		else {
			sum += (b - a) * 6;
		}
		a = b;
	}
	printf("%d", sum);
}