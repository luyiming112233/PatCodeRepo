#include<cstdio>
#include<string>
#include<string.h>
using namespace std;

#define maxn 1000010
#define plen 100010

char str[maxn], pattern[plen];
int match[plen];

void buildMatch() {
	int i, j;
	int len = strlen(pattern);
	match[0] = -1;
	for (j = 1; j < len; j++) {
		i = match[j - 1];
		while (i >= 0 && pattern[i + 1] != pattern[j])
			i = match[i];
		if (pattern[i + 1] == pattern[j])
			match[j] = i + 1;
		else
			match[j] = -1;
	}
}

int KMP() {
	int n = strlen(str), m = strlen(pattern);
	int s=0, p=0;
	if (n < m) return -1;
	buildMatch();
	while (s < n&&p < m) {
		if (str[s] == pattern[p]) {
			s++;
			p++;
		}
		else if (p > 0) {
			p = match[p - 1] + 1;
		}
		else {
			s++;
		}
	}
	if (p == m)
		return s - m;
	else
		return -1;
}

int main() {
	scanf("%s", str);
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("\n%s", pattern);
		int index = KMP();
		if (index == -1) printf("Not Found\n");
		else printf("%s\n", str + index);
	}
	return 0;
}

