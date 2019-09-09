#include<cstdio>
#include<algorithm>
#include<math.h>
using namespace std;

#define maxn 100010

int ha[maxn];
int MSize, N, M;

bool isPrime(int num) {
	if (num == 0 || num == 1) return false;
	if (num == 2) return true;
	for (int i = 2; i <= sqrt((double)num); i++)
		if (num%i == 0) return false;
	return true;
}

void build() {
	for (; MSize < maxn; MSize++)
		if (isPrime(MSize))
			break;
}

int find(int value,int &index) {
	int time = 0;
	index = -1;
	int key = value % MSize,temp;
	for (int i = 0; i <= MSize; i++) {
		temp = (key + i * i) % MSize;
		time++;
		if (ha[temp] == value || ha[temp]==-1) {
			index = temp;
			return time;
		}
	}
	return time;
}

int main() {
	scanf("%d %d %d", &MSize, &N, &M);
	fill(ha, ha + maxn, -1);
	int num,index,sum=0,time;
	build();
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		find(num, index);
		if (index == -1) printf("%d cannot be inserted.\n", num);
		else ha[index] = num;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &num);
		time = find(num, index);
		sum += time;
	}
	printf("%.1f", 1.0 * sum / M);
	return 0;
}