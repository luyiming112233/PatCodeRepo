#include<cstdio>
#include<vector>
using namespace std;

#define maxn 1010

int hsize = 0;
int arry[maxn] = {-1000000};

void insert(int num) {
	hsize++;
	int temp = hsize;
	while (temp!= 0) {
		if (num < arry[temp/2]) {
			arry[temp] = arry[temp / 2];
		}
		else {
			arry[temp] = num;
			break;
		}
		temp /= 2;
	}
}

void searchPath(int index) {
	bool first = true;
	while (index != 0) {
		if(first) {
			printf("%d", arry[index]);
			first = false;
		}
		else {
			printf(" %d", arry[index]);
		}
		index /= 2;
	}
	printf("\n");
}

int main() {
	int N, M,num,index;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		insert(num);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &index);
		searchPath(index);
	}
	return 0;
}
