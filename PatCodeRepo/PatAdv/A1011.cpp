#include<cstdio>

int main() {
	double a[3][3],sum=1;
	int r;
	for (int i = 0; i < 3; i++) {
		scanf("%lf %lf %lf", &a[i][0], &a[i][1], &a[i][2]);
	}
	for (int i = 0; i < 3; i++) {
		r = 0;
		if (a[i][1] > a[i][0])
			r = 1;
		if (a[i][2] > a[i][r])
			r = 2;
		switch (r)
		{
		case 0:printf("W "); break;
		case 1:printf("T "); break;
		case 2:printf("L "); break;
		}
		sum *= a[i][r];
	}
	sum = (sum * 0.65 - 1)*2;
	printf("%.2lf", sum);
}