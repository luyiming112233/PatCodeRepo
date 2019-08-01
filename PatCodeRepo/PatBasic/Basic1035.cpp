#include<cstdio>
#include<algorithm>
using namespace std;


bool same(int a[], int b[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}

int main() {
	int n,i,j;
	scanf("%d", &n);
	int *a = new int[n], *b = new int[n];
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	bool insert = true;
	i = n - 1;
	while (i > -1) {
		if (a[i] != b[i])
			break;
		i--;
	}
	for (j = 0; j < i - 1; j++) {
		if (b[j] > b[j + 1]) {
			insert = false;
			break;
		}
	}

	//如果是插入排序
	if (insert) {
		printf("Insertion Sort\n");
		i = 2;
		sort(a, a + i);
		while (!same(a,b,n))
		{
			i++;
			sort(a, a + i);
		}
		if(i<n)
    		i++;
		sort(a, a + i);
		for (j = 0; j < n; j++) {
			if (j != 0)
				printf(" %d", a[j]);
			else
				printf("%d", a[j]);
		}
	}
	else {
		printf("Merge Sort\n");
		i = 2;
		while (!same(a,b,n))
		{
			j = 0;
			while (j + i <= n  ) {
				sort(a + j, a + j + i);
				j += i;
			}
			sort(a + j, a + n);
			i *= 2;
		}
		j = 0;
		while (j + i <= n) {
			sort(a + j, a + j + i);
			j += i;
		}
		sort(a + j, a + n);
		for (j = 0; j < n; j++) {
			if (j != 0)
				printf(" %d", a[j]);
			else
				printf("%d", a[j]);
		}
	}
}