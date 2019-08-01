#include<cstdio>

#define max 1010

int main() {
	char str1[max], str2[max];
	int a[128] = { 0 },lost=0,more=0;
	scanf("%s", str1);
	scanf("%s", str2);
	for (int i = 0; i < max; i++) {
		if (str1[i] == '\0')
			break;
		a[(int)str1[i]]++;
	}
	for (int i = 0; i < max; i++) {
		if (str2[i] == '\0')
			break;
		a[(int)str2[i]]--;
	}
	for (int i = 0; i < 128; i++) {
		if (a[i] < 0) {
			lost -= a[i];
		}
		else {
			more += a[i];
		}
	}
	if (lost == 0) {
		printf("Yes %d\n", more);
	}
	else {
		printf("No %d\n", lost);
	}
	return 0;

}