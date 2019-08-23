#include<cstdio>

#define maxn 1000010

char str[maxn], a[maxn];

int main() {
	int N,len;
	scanf("%s", str);
	scanf("%d", &N);
	for (len = 0; len < maxn; len++)
		if (str[len] == '\0')
			break;
	for (int ni = 0; ni < N; ni++) {
		int start=0;
		int ai;
		bool flag = false;
		scanf("\n%s", a);
		while (start < len && !flag) {	
			for (ai = 0; ai < maxn; ai++) {
				if (a[ai] == '\0') {
					flag = true;
					break;
				}
				if (a[ai] != str[start + ai])
					break;
			}
			if (!flag)
				start += (ai+1);
		}
		if (flag)
			printf("%s\n", str + start);
		else
			printf("Not Found\n");
	}
	return 0;
}