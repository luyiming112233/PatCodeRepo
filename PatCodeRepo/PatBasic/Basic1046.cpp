#include<cstdio>

int main() {
	int n,sum1,sum2,a1,a2,l1=0,l2=0;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d %d %d %d", &a1, &sum1, &a2, &sum2);
		if (a1 + a2 == sum1 && a1 + a2 == sum2)
			continue;
		if (a1 + a2 == sum1)
			l2++;
		else if (a1 + a2 == sum2)
			l1++;
	}
	printf("%d %d\n", l1, l2);
	return 0;
}