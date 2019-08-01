#include<cstdio>

#define maxn 100010

int a[maxn],ink[maxn],startfind;

void swap(int i, int j) {
	//����ֵ����
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
	//�±꽻��
	t = ink[a[i]];
	ink[a[i]] = ink[a[j]];
	ink[a[j]] = t;
}

int main() {
	int N,step=0,d;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		ink[a[i]] = i;
	}
	startfind = 0;
	while (true) {
		if (ink[0] == 0) {
			for (d = startfind; (d+startfind)%N < N; d++) {
				if (a[d] != d) {
					startfind = d % N;
					break;
				}
			}
			if (d == N)
				break;
			else {
				step++;
				swap(0, d);
			}
		}
		else {
			step++;
			//����0��0��Ӧ�±�λ�õ���
			//ink[0]��ʾ0���±꣬ink[ink[0]]��ʾ0��Ӧ�±�������±�
			swap(ink[0], ink[ink[0]]);
		}
	}
	printf("%d", step);
}