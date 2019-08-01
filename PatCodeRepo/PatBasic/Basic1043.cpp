#include<cstdio>

#define max 10010

int main() {
	char str[max], ch[6] = {'P','A','T','e','s','t'};
	scanf("%s", str);
	int a[6] = { 0 },time = 0;
	for (int i = 0; i < max; i++) {
		if (str[i] == '\0')
			break;
		switch (str[i])
		{
		case 'P':a[0]++; break;
		case 'A':a[1]++; break;
		case 'T':a[2]++; break;
		case 'e':a[3]++; break;
		case 's':a[4]++; break;
		case 't':a[5]++; break;
		}
	}
	for (int i = 0; i < 6; i++) {
		if (time < a[i])
			time = a[i];
	}
	for (int i = 0; i < time; i++) {
		for (int j = 0; j < 6; j++) {
			if (a[j] > 0) {
				a[j]--;
				printf("%c", ch[j]);
			}
		}
	}
	printf("\n");
	return 0;
}