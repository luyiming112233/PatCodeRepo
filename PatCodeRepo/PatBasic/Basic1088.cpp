#include<cstdio>
#include<math.h>
#define error 0.0000001

bool isSame(double a, double b) {
	if (fabs(a - b) < error)
		return true;
	return false;
}

int main() {
	int n, X, Y, cn;
	double temp[3], answer[3] = { 0 };
	scanf("%d %d %d", &n, &X, &Y);

	for (int i = 10; i < 100; i++) {
		temp[0] = i;
		cn = i;
		temp[1] = 0;
		while (cn != 0) {
			temp[1] = temp[1] * 10 + (cn % 10);
			cn /= 10;
		}
		if (isSame(fabs(temp[0] - temp[1]) / X, temp[1] / Y)) {
			answer[0] = temp[0];
			answer[1] = temp[1];
			answer[2] = temp[1] / Y;
		}
	}

	if (answer[0] == 0)
		printf("No Solution\n");
	else {
		printf("%d", (int)answer[0]);
		for (int i = 0; i < 3; i++) {
			if (n < answer[i])
				printf(" Cong");
			else if (n>answer[i])
				printf(" Gai");
			else
			    printf(" Ping");
		}
		printf("\n");
	}
}