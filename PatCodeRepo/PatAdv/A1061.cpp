#include<cstdio>

#define maxn 70

bool isSameCapital(char a,char b) {
	if (a<'A' || a>'G' || b<'A' || b>'G' || a!=b) {
		return false;
	}
	return true;
}

bool isNumEng(char a) {
	if (a >= '0' && a <= '9') {
		return true;
	}
	if (a >= 'A' && a <= 'N') {
		return true;
	}
	return false;
}

bool isSameChar(char a, char b) {
	if (a==b && isNumEng(a) && isNumEng(b)) {
		return true;
	}
	return false;
}

bool isEng(char a) {
	if (a >= 'a' && a <= 'z')
		return true;
	if (a >= 'A' && a <= 'Z')
		return true;
	return false;
}

bool isSameEng(char a, char b) {
	if (a == b && isEng(a) && isEng(b)) {
		return true;
	}
	return false;
}

void print_c1(char c) {
	switch (c)
	{
	case 'A':printf("MON"); break;
	case 'B':printf("TUE"); break;
	case 'C':printf("WED"); break;
	case 'D':printf("THU"); break;
	case 'E':printf("FRI"); break;
	case 'F':printf("SAT"); break;
	case 'G':printf("SUN"); break;
	}
}

void print_c2(char c){
	if (c >= '0' && c <= '9') {
		printf("%02d", c - '0');
	}
	else if (c>='A' && c<='N') {
		int a = c - 'A' + 10;
		printf("%d", a);
	}
}

int main() {
	char a1[maxn], a2[maxn], b1[maxn], b2[maxn];
	char c1, c2;
	int min = 0,i;
	scanf("%s", a1);
	scanf("%s", a2);
	scanf("%s", b1);
	scanf("%s", b2);
	for (i = 0; i < maxn; i++) {
		if (isSameCapital(a1[i], a2[i])) {
			c1 = a1[i];
			break;
		}
	}
	i++;
	for (; i < maxn; i++) {
		if (isSameChar(a1[i],a2[i])) {
			c2 = a1[i];
			break;
		}
	}
	for (min = 0; min < maxn; min++) {
		if (isSameEng(b1[min], b2[min]))
			break;
	}
	print_c1(c1);
	printf(" ");
	print_c2(c2);
	printf(":%02d", min);
	return 0;
}