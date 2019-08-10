#include<cstdio>
#include<algorithm>
using namespace std;

#define maxn 10010

int a[maxn];

int getType(int c) {
	int temp = c,next;
	while (a[c] > 0) {
		c = a[c];
	}
	//将路径上所有的点指向根
	while (a[temp] > 0) {
		next = a[temp];
		a[temp] = c;
		temp = next;
	}
	return c;
}

int main() {
	fill(a, a + maxn, -1);
	int N;
	char s;
	int c1, c2;
	int root1, root2;
	scanf("%d", &N);
	while (true) {
		scanf("%c", &s);
		if (s == 'S')
			break;
		scanf("%d %d", &c1, &c2);
		if (s == 'I') {
			root1 = getType(c1);
			root2 = getType(c2);
			if (root1 != root2) {
				if (a[root1] < a[root2]) {
					a[root1] += a[root2];
					a[root2] = root1;
				}
				else {
					a[root2] += a[root1];
					a[root1] = root2;
				}
			}
		}
		else if (s == 'C') {
			root1 = getType(c1);
			root2 = getType(c2);
			if (root1 == root2) {
				printf("yes\n");
			}
			else {
				printf("no\n");
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (a[i] < 0)
			sum++;
	}
	if (sum == 1)
		printf("The network is connected.\n");
	else {
		printf("There are %d components.\n",sum);
	}
	return 0;
}