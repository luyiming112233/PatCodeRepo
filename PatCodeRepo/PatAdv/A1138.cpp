#include<cstdio>

#define maxn 50010

int preOrder[maxn], inOrder[maxn];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &preOrder[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &inOrder[i]);
	}
	int preL = 0, preR = N-1, inL = 0, inR = N - 1;
	int TpreL, TpreR, TinL, TinR;
	int root, index;
	while (true) {
		if (preL == preR) {
			printf("%d", preOrder[preR]);
			break;
		}
		root = preOrder[preL];
		for (int i = inL; i <= inR; i++) {
			if (inOrder[i] == root) {
				index = i;
				break;
			}
		}
		//有左儿子
		if (index != inL) {
			TpreL = preL + 1;
			TpreR = preL + index - inL;
			TinL = inL;
			TinR = index - 1;
		}
		//没有左儿子,查找右儿子
		else {
			TpreL = preL + index - inL + 1;
			TpreR = preR;
			TinL = index + 1;
			TinR = inR;
		}
		preL = TpreL;
		preR = TpreR;
		inL = TinL;
		inR = TinR;
	}
	return 0;
}