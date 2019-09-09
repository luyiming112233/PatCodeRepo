#include<cstdio>

#define maxn 100010

int a[maxn];

void swap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

int main() {
	int N,index,step=0,temp;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &index);
		a[index] = i;
	}
	int find = 1;
	bool flag = true;
	while (flag) {
		if (a[0] != 0) {
			step++;
			swap(a[0], a[a[0]]);
		}
		else {
			for (; find < N; find++) 
				if (a[find] != find)
					break;
			if (find == N)
				flag = false;
			else {
				step++;
				swap(a[0], a[find]);
			}	
		}
	}
	printf("%d", step);
	return 0;
}