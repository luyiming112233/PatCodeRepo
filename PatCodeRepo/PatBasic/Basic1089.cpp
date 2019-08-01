#include<cstdio>

int main() {
	int a[101] = { 0 }, b[101] = { 0 }, N, bad, good, answer[2] = {0};
	scanf("%d", &N);
	for (int i = 1; i <= N;i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < N; i++) {
		b[i] = 1;
		for (int j = i + 1; j <= N; j++) {
			b[j] = 1;
			bad = 0;
			good = 0;
			for (int k = 1; k <= N; k++) {
				//指认狼人
				if (a[k] < 0) {
					//说了假话，将好人指为狼人
					if (b[-a[k]] == 0) {
					    //k是狼人
						if (b[k] == 1) {
							bad++;
						}
						else {
							good++;
						}
					}
				}
				//指认好人
				if (a[k] > 0) {
					//说了假话，将好人指为狼人
					if (b[a[k]] == 1) {
						//k是狼人
						if (b[k] == 1) {
							bad++;
						}
						else {
							good++;
						}
					}
				}
			}
			if (bad == 1 && good == 1) {
				answer[0] = i;
				answer[1] = j;
				i = N + 1;
				j = N + 1;
			}
			b[j] = 0;
		}
		b[i] = 0;
	}
	if (answer[0] == 0)
		printf("No Solution\n");
	else
    	printf("%d %d\n", answer[0], answer[1]);
	return 0;
}