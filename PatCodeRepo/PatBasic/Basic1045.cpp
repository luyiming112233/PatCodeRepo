#include<cstdio>
#include<algorithm>
using namespace std;

#define max 100010

int nums[max] = {0};

int main() {
	int n,num=0,n_max;
	scanf("%d", &n);
	bool flag;
	int *a = new int[n],*b=new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b, b + n);
	n_max = a[0];
	for (int i = 0; i < n; i++) {
		//可能是主元
		if (n_max <= a[i]) {
			if (a[i] == b[i]) {
				nums[num] = a[i];
				num++;
			}
			n_max = a[i];
		}
	}
	printf("%d\n", num);
	for (int i = 0; i < num; i++) {
		if (i != 0) {
			printf(" %d", nums[i]);
		}
		else
    		printf("%d", nums[i]);
	}
	printf("\n");
}