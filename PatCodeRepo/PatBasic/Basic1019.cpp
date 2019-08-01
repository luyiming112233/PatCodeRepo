#include <stdio.h>
#include<algorithm>
using namespace std;

int main(void) {
	int n, min, max, num[4];
	scanf("%d", &n);
	while (true) {
		min = 0, max = 0;
		for (int i = 0; i < 4; i++) {
			num[i] = n % 10;
			n /= 10;
		}
		sort(num, num + 4);
		min = num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];
		max = num[0] + num[1] * 10 + num[2] * 100 + num[3] * 1000;
		n = max - min;
		printf("%04d - %04d = %04d\n", max, min, n);
		if (n == 0 || n == 6174)
			break;
	}
	return 0;
}