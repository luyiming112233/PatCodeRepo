#include<cstdio>

#define size 1010

int main() {
	int n, a[size] = {0},tid,pid,grade,maxid=0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d-%d %d", &tid, &pid, &grade);
		a[tid] += grade;
	}
	for (int i = 0; i < size; i++) {
		if (a[i] > a[maxid])
			maxid = i;
	}
	printf("%d %d\n", maxid, a[maxid]);
	return 0;
}