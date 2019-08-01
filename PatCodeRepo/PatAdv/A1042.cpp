#include<cstdio>

#define maxn 54

void printCard(int num) {
	switch (num / 13) {
	case 0:printf("S"); break;
	case 1:printf("H"); break;
	case 2:printf("C"); break;
	case 3:printf("D"); break;
	case 4:printf("J"); break;
	}
	printf("%d", num % 13 + 1);
}

int main() {
	int K,th[maxn],card[maxn],temp[maxn];
	scanf("%d", &K);
	for (int i = 0; i < maxn; i++) {
		card[i] = i;
	}
	for (int i = 0; i < maxn; i++) {
		scanf("%d", &th[i]);
		th[i]--;
	}
	for (int k = 0; k < K; k++) {
		for (int i = 0; i < maxn; i++)
			temp[i] = card[i];
		for (int i = 0; i < maxn; i++) {
			card[th[i]] = temp[i];
		}
	}
	for (int i = 0; i < maxn; i++) {
		if (i == 0){
			printCard(card[i]);
		}
		else {
			printf(" ");
			printCard(card[i]);
		}
	}
	return 0;
}