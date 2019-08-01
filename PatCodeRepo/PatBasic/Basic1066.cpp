#include<cstdio>

int main() {
	int M, N, A, B, v;
	int a[500][500] = { 0 };
	scanf("%d%d%d%d%d", &M, &N, &A, &B, &v);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			scanf("%d", &a[i][j]);
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++){
			if (a[i][j] >= A && a[i][j] <= B) {
				a[i][j] = v;
			}
			if (j == 0)
				printf("%03d", a[i][j]);
			else
				printf(" %03d", a[i][j]);
		}	
		printf("\n");
	}
}