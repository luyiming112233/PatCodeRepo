#include<cstdio>

#define maxn 65

int FCM(char a, char b) {
	if (a != b) return -1;
	if (a >= 'A' && a <= 'G') return a - 'A' + 1;
	return -1;
}

int FCM2(char a, char b) {
	if (a != b) return -1;
	if (a >= '0' && a <= '9') return a - '0';
	if (a >= 'A' && a <= 'N') return a - 'A' + 10;
	return -1;
}

bool FCM3(char a, char b) {
	if (a != b) return false;
	if (a >= 'a' && a <= 'z') return true;
	if (a >= 'A' && a <= 'Z') return true;
	return false;
}

int main() {
	char s1[maxn], s2[maxn], s3[maxn], s4[maxn];
	scanf("%s", s1);
	scanf("\n%s", s2);
	scanf("\n%s", s3);
	scanf("\n%s", s4);
	int dd, hh, mm;
	int i;
	for (i = 0; i < maxn; i++) {
		dd = FCM(s1[i], s2[i]);
		if (dd != -1) break;
	}
	i++;
	for (; i < maxn; i++) {
		hh = FCM2(s1[i], s2[i]);
		if (hh != -1) break;
	}
	for (mm = 0; mm < maxn; mm++)
		if (FCM3(s3[mm],s4[mm]))
			break;
	switch (dd) {
	case 1:printf("MON"); break;
	case 2:printf("TUE"); break;
	case 3:printf("WED"); break;
	case 4:printf("THU"); break;
	case 5:printf("FRI"); break;
	case 6:printf("SAT"); break;
	case 7:printf("SUN"); break;
	}
	printf(" %02d:%02d", hh, mm);
	return 0;
}