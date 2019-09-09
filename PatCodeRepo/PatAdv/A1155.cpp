#include<cstdio>
#include<vector>
using namespace std;

#define maxn 1010

int heap[maxn];
int N;
bool isMax = false, isMin = false;
vector<int> temp;

void display() {
	for (int i = 0; i < temp.size(); i++) {
		if (i == 0) printf("%d", temp[i]);
		else printf(" %d", temp[i]);
	}
	printf("\n");
}

void DFS(int i) {
	temp.push_back(heap[i]);
	if (2 * i <= N) {
		if (2 * i + 1 <= N) {
			if (heap[i] > heap[2 * i + 1]) isMax = true;
			else if (heap[i] < heap[2 * i] + 1) isMin = true;
			DFS(2 * i + 1);
		}
		DFS(2 * i);
		if (heap[i] > heap[2 * i]) isMax = true;
		else if (heap[i] < heap[2 * i]) isMin = true;
	}
	else {
		display();
	}
	temp.pop_back();
}


int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &heap[i]);
	DFS(1);
	if (isMax&&isMin) printf("Not Heap");
	else if (isMax) printf("Max Heap");
	else printf("Min Heap");
	return 0;
}