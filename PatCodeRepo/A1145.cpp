#include<cstdio>

#define maxn 100010

int num[maxn] = { 0 };
int hash[maxn] = { 0 };
int TSize;

bool isPrime(int a) {
	if (a == 1)
		return false;
	if (a == 2)
		return true;
	for (int i = 2; i*i <= a; i++) {
		if (a%i == 0)
			return false;
	}
	return true;
}

int getTsize(int MSize) {
	while (true) {
		if (isPrime(MSize)) {
			return MSize;
		}
		MSize++;
	}
	return 0;
}

int insert(int key) {
	int t = 0, index;
	for (t= 0; t <= TSize; t++) {
		index = (key + t * t) % TSize;
		if (hash[index] == 0) {
			hash[index] = key;
			t++;
			break;
		}
	}
	return t;
}

int find(int key) {
	int t = 0, index;
	for (t = 0; t <= TSize; t++) {
		index = (key + t * t) % TSize;
		if (hash[index] == key || hash[index]==0) {
			t++;
			break;
		}
	}
	return t;
}

int main() {
	int MSize, N, M,key,t;
	int sum = 0;
	scanf("%d %d %d", &MSize, &N, &M);
	TSize = getTsize(MSize);
	for (int i = 0; i < N; i++) {
		scanf("%d", &key);
		t = insert(key);
		if (t == TSize+1) {
			printf("%d cannot be inserted.\n", key);
		}
		num[key] = t;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &key);
		if (num[key] == 0) {
			num[key] = find(key);
		}
		sum += num[key];
	}
	double an = 1.0*sum / M;
	printf("%.1f", an);
	return 0;
}