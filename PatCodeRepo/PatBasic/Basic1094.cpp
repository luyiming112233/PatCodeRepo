#include<cstdio>

#define ssize 1010

bool judge(int n) {
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0)
			return false;
	}
	if (n == 0 || n == 1)
		return false;
	return true;
}

int main() {
	char str[ssize];
	int L, K, temp;
	scanf("%d %d", &L, &K);
	scanf("%s", str);
	bool find = false;

	for (int i = 0; i <= L - K; i++) {
		temp = 0;
		for (int j = 0; j < K; j++) {
			temp = temp * 10 + (str[i + j] - '0');
		}
		if (judge(temp)) {
			for (int t = 0; t < K; t++) {
				printf("%c", str[i + t]);
			}
			find = true;
			break;
		}
	}
	if (find == false)
		printf("404\n");
	return 0;
}