#include<cstdio>
#include<stack>
#include<string.h>

using namespace std;

#define bnum 317
#define maxn 100010

stack<int> sta;
int a[maxn] = { 0 };
int block[bnum] = { 0 };

void pop() {
	int value = sta.top();
	sta.pop();
	block[value / bnum]--;
	a[value]--;
	printf("%d\n", value);
}

void median() {
	int n = (sta.size() + 1) / 2;
	int s = 0;
	for (int i = 0; i < bnum; i++) {
		if (s + block[i] < n) {
			s += block[i];
		}
		else {
			for (int k = 0; k < bnum; k++) {
				if (a[i*bnum + k]+s < n)
					s += a[i*bnum + k];
				else {
					printf("%d\n", i*bnum + k);
					break;
				}
			}
			break;
		}
	}
}

void push(int value) {
	sta.push(value);
	block[value / bnum]++;
	a[value]++;
}

int main() {
	int N,value;
	char op[20];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", op);
		if (strcmp(op, "Pop")==0) {
			if (sta.size() == 0)
				printf("Invalid\n");
			else {
				pop();
			}
		}
		else if (strcmp(op, "PeekMedian") == 0) {
			if (sta.size() == 0)
				printf("Invalid\n");
			else {
				median();
			}
		}
		else if (strcmp(op, "Push") == 0) {
			scanf("%d", &value);
			push(value);
		}
	}
	return 0;
}