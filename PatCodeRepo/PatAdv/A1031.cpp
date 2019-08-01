#include<cstdio>

#define maxn 90

int main() {
	char str[maxn];
	int len,k=0,tk,n2;
	scanf("%s", str);
	for (len = 0;true; len++) {
		if (str[len] == '\0')
			break;
	}
	for (n2 = 3; n2 < len;n2++) {
		if ((len - n2) % 2 == 1)
			continue;
		tk = (len - n2 + 2) / 2;
		if (tk > k && tk<=n2)
			k = tk;
	}
	n2 = len + 2 - 2 * k;
	for (int i = 0; i < k-1; i++) {
		printf("%c", str[i]);
		for (int j = 0; j < n2 - 2; j++)
			printf(" ");
		printf("%c\n", str[len - 1 - i]);
	}
	for (int i = 0; i < n2; i++) {
		printf("%c", str[i + k-1]);
	}
	return 0;
}