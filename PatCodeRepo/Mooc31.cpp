#include<cstdio>
#include<vector>
using namespace std;

#define maxn 110000

bool isPrime(int num) {
	if (num == 1)
		return false;
	if (num == 2)
		return true;
	for (int i = 2; i*i <= num; i++) 
		if (num%i == 0) return false;
	return true;
}

int getTSize(int ms) {
	while (true) {
		if (isPrime(ms)) break;
		ms++;
	}
	return ms;
}

int a[maxn] = {0};
int MS, TS, N;

int find(int value) {
	int key = value % TS;
	int temp;
	for (int i = 0; i < TS; i++) {
		temp = (key + i * i) % TS;
		if (a[temp] == 0) {
			a[temp] = value;
			return temp;
		}
	}
	return -1;
}

int main() {
	scanf("%d %d", &MS, &N);
	TS = getTSize(MS);
	vector<int> v;
	int num,index;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	for (int i = 0; i < v.size(); i++) {
		index = find(v[i]);
		if (i != 0) printf(" ");
		if (index == -1) printf("-");
		else printf("%d", index);
	}
	return 0;
}