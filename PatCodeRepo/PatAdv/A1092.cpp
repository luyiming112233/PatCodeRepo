#include<cstdio>

#define maxn 1010

int main() {
	char str[maxn];
	int a[128] = { 0 }, b[128] = { 0 },suma=0,sumb=0;
	scanf("%s", str);
	for (suma = 0; suma < maxn; suma++) {
		if (str[suma] == '\0')
			break;
		a[str[suma]]++;
	}
	scanf("%s", str);
	for (sumb = 0; sumb < maxn; sumb++) {
		if (str[sumb] == '\0')
			break;
		b[str[sumb]]++;
	}
	int lost = 0;
	for (int i = 0; i < 128; i++) {
		if (a[i] < b[i]) {
			lost +=(b[i] - a[i]);
		}
	}
	if (lost > 0) {
		printf("No %d", lost);
	}
	else {
		printf("Yes %d", suma - sumb);
	}
	return 0;
}