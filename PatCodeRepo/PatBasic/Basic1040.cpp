#include<cstdio>

#define max 100010

int main() {
	char str[max];
	scanf("%s", str);
	int left[3] = { 0 }, right[3] = { 0 },sum=0;
	for (int i = 0; i < max; i++) {
		if (str[i] == '\0')
			break;
		if (str[i] == 'P')
			right[0]++;
		//else if (str[i] == 'A')
		//	right[1]++;
		else if (str[i] == 'T')
			right[2]++;
	}
	for (int i = 0; i < max; i++) {
		if (str[i] == '\0')
			break;
		if (str[i] == 'P') {
			left[0]++;
			right[0]--;
		}
		else if (str[i] == 'A') {
			sum = (sum + left[0] * right[2]) % 1000000007;
		}
		else if (str[i] == 'T') {
			left[2]++;
			right[2]--;
		}
	}
	printf("%d\n", sum);
	return 0;
}