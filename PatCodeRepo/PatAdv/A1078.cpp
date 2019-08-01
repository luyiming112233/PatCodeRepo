#include<cstdio>

#define maxn 10010

int nums[maxn] = { 0 };

bool isPrime(int num) {
	if (num == 0 || num == 1)
		return false;
	for (int i = 2; i*i <= num; i++) {
		if (num%i == 0)
			return false;
	}
	return true;
}

int getTSize(int num) {
	for(int i=num;i<10000000;i++){
		if (isPrime(i))
			return i;
	}
	return num;
}

int findHush(int k,int TSize) {
	int nk = 0;
	for (int i = 0; i <= TSize; i++) {
		nk = (k % TSize+i*i)%TSize;
		if (nums[nk] == 0)
			return nk;
	}
	return -1;
}

int main() {
	int MSize, N, TSize,num,k;
	scanf("%d %d", &MSize, &N);
	TSize = getTSize(MSize);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		k = findHush(num, TSize);
		if (i != 0) {
			printf(" ");
		}
		if (k!=-1) {
			nums[k] = 1;
			printf("%d", k);
		}
		else {	
		    printf("-");	
		}
	}
	return 0;
}