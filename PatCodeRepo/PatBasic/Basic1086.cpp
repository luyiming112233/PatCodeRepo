#include<cstdio>

int main() {
	int a, b, num;
	bool first = true;
	while(~scanf("%d %d", &a, &b)) {
		num = a * b;
		first = true;
		while (num!=0)		{
			if (first) {
				if (num % 10 != 0) {
					printf("%d", num % 10);
					first = false;
				}
			}
			else {
				printf("%d", num % 10);
			}
			num /= 10;
		}
		printf("\n");
	}
	return 0;
}