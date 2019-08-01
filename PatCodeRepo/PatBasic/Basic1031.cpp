#include<cstdio>

int main() {
	int n, z;
	bool flag = true, temp;
	char str[19], m;
	int a[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	char z2m[12] = { '1','0','X','9','8','7','6','5','4','3','2' };
	scanf("%d", &n);
	while (n--) {
		scanf("%s", str);
		z = 0;
		temp = true;
		for (int i = 0; i < 17; i++) {
			if (str[i] - '0' < 0 || str[i] - '0'>9) {
				temp = false;
				break;
			}
			z = z + a[i] * (str[i] - '0');
		}
		if (z2m[z % 11] != str[17]) {
			temp = false;
		}
		if (temp == false) {
			printf("%s\n", str);
			flag = false;
		}
	}
	if (flag)
		printf("All passed\n");
	return 0;
}