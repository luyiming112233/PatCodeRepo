#include<cstdio>
using namespace std;

#define maxn 100010
#define mode 1000000007

int main() {
	char str[maxn];
	int Pnum = 0, Tnum = 0, sum = 0;
	scanf("%s", str);
	for (int i = 0; i < maxn; i++) {
		if (str[i] == '\0')
			break;
		if (str[i] == 'T') {
			Tnum++;
		}
	}
	for (int i = 0; i < maxn; i++) {
		if (str[i] == '\0')
			break;
		if (str[i] == 'P')
			Pnum++;
		else if (str[i] == 'A') {
			sum = (sum + Pnum * Tnum) % mode;
		}
		else if (str[i] == 'T')
			Tnum--;
	}
	printf("%d", sum);
	return 0;
}