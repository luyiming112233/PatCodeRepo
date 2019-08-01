#include<cstdio>

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	int *a = new int[M],*answer = new int[M],grade,t;
	for (int i = 0; i < M; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < M; i++) {
		scanf("%d", &answer[i]);
	}

	for (int i = 0; i < N; i++) {
		grade = 0;
		for (int j = 0; j < M; j++) {
			scanf("%d", &t);
			if(answer[j]==t)
    			grade += a[j];
		}
		printf("%d\n", grade);
	}
	return 0;
}