#include<cstdio>

int main() {
	int K,sum,maxsum,max_f,max_l,first,last;
	bool allnegative = true;
	scanf("%d", &K);
	int *a = new int[K];
	for (int i = 0; i < K; i++) {
		scanf("%d", &a[i]);
		if (a[i] >= 0)
			allnegative = false;
	}
	if (allnegative) {
		printf("0 %d %d", a[0], a[K - 1]);
	}
	else {
		sum = 0;
		maxsum = -1;
		first = 0;
		last = 0;
		while (last<K){
			first = last;
			last = first;
			sum = 0;
			while (sum>=0 && last<K){
				sum += a[last];
				if (sum > maxsum) {
					maxsum = sum;
					max_f = first;
					max_l = last;
				}
				last++;
			}
		}
		printf("%d %d %d", maxsum, a[max_f], a[max_l]);
	}
	return 0;
}