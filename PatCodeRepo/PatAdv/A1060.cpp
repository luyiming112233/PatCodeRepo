#include<cstdio>
#include<string.h>

#define maxn 120

struct node {
	char num[maxn];
	int k;
}na,nb;

void tran(int n, char *s, node &no) {
	int w = 0;
	bool isFloat = false,isZore = true;
	for (w = 0; w < maxn; w++) {
		if (s[w] == '\0')
			break;
		if (s[w] == '.') {
			isFloat = true;
			break;
		}
	}
	no.k = w;
	int len;
	for (len = 0; len < maxn; len++) {
		if (s[len] == '\0')
			break;
	}
	//整数
	if (!isFloat) {
		//整数为0
		for (int i = 0; i < w; i++) {
			if (s[i] != '0') {
				isZore = false;
				break;
			}
		}
		if (isZore)
			no.k = 0;
		for (int i = 0; i < n; i++) {
			if (i < len)
				no.num[i] = s[i];
			else
				no.num[i] = '0';
		}
	}
	else {
	    //整数部分非0
		for (int i = 0; i < w; i++) {
			if (s[i] != '0') {
				isZore = false;
				break;
			}
		}
		if (!isZore) {
			int start = 0;
			//保证第一个数字非0
			while (true) {
				if (s[start] != '0')
					break;
				start++;
			}
			for (int i = 0; i < n; i++) {
				if (s[i+ start] == '.')
					continue;
				if (i < len)
					no.num[i] = s[i+ start];
				else
					no.num[i] = '0';
			}
		}
		else {
			int tw = 0,vv=0;
			bool allZero = true;
			for (int i = w + 1; i < len; i++) {
				if (s[i] == '0') {
					tw--;
				}
				else {
					allZero = false;
					vv = i;
					break;
				}
			}
			if (allZero) {
				for (int i = 0; i < n; i++) {
					no.num[i] = '0';
				}
				no.k = 0;
			}
			else {
				for (int i = 0; i < n; i++) {
					if (vv + i < len) {
						no.num[i] = s[vv + i];
					}
					else {
						no.num[i] = '0';
					}
				}
				no.k = tw;
			}
		}
	}
	no.num[n] = '\0';
}

void display(node n) {
	printf("0.%s*10^%d", n.num, n.k);
}

int main() {
	int N;
	char a[maxn], b[maxn];
	scanf("%d", &N);
	scanf("%s", a);
	scanf("%s", b);
	tran(N, a, na);
	tran(N, b, nb);
	if (strcmp(na.num, nb.num) == 0 && na.k == nb.k) {
		printf("YES");
		printf(" ");
		display(na);
	}
	else {
		printf("NO");
		printf(" ");
		display(na);
		printf(" ");
		display(nb);
	}
	return 0;
}