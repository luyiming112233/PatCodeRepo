#include<cstdio>

#define maxn 20

struct node {
	char c;
	int left, right;
	node() {
		left = -1, right = -1;
	}
}A[maxn],B[maxn];

bool judge(int Aroot, int Broot) {
	if (Aroot == -1 && Broot == -1)
		return true;
	if (Aroot == -1 || Broot == -1)
		return false;
	if (A[Aroot].c != B[Broot].c)
		return false;
	if (judge(A[Aroot].left, B[Broot].left) && judge(A[Aroot].right, B[Broot].right))
		return true;
	if (judge(A[Aroot].left, B[Broot].right) && judge(A[Aroot].right, B[Broot].left))
		return true;
	return false;
}

int isAroot[maxn] = { 0 }, isBroot[maxn] = { 0 };

int main() {
	int m, n;
	char cl, cr;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("\n%c %c %c", &A[i].c, &cl, &cr);
		if (cl != '-') { 
			A[i].left = cl - '0'; 
			isAroot[cl - '0']++;
		}
		if (cr != '-') { 
			A[i].right = cr - '0'; 
			isAroot[cr - '0']++;
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("\n%c %c %c", &B[i].c, &cl, &cr);
		if (cl != '-') {
			B[i].left = cl - '0';
			isBroot[cl - '0']++;
		}
		if (cr != '-') {
			B[i].right = cr - '0';
			isBroot[cr - '0']++;
		}
    }
	if (m != n) {
		printf("No");
		return 0;
	}
	int ARoot=-1, BRoot=-1;
	for (int i = 0; i < m; i++) {
		if (isAroot[i] == 0) {
			ARoot = i;
			break;
		}
	}
	for (int i = 0; i < m; i++) {
		if (isBroot[i] == 0) {
			BRoot = i;
			break;
		}
	}
	if (judge(ARoot, BRoot)) printf("Yes");
	else printf("No");
	return 0;
}