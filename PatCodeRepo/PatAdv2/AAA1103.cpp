#include<cstdio>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

vector<int> vn, Kn,temp,answer;
int fsum = 0;
int N, K, P;

void update() {
	int fs = 0;
	for (int i = 0; i < temp.size(); i++)
		fs += temp[i];
	if (fs > fsum) {
		fsum = fs;
		answer = temp;
	}
}

void DFS(int index, int sum) {
	if (temp.size() == K && sum==N) update();
	else if (temp.size() < N && sum<N) {
		for (int i = index; i < vn.size(); i++) {
			if (sum + Kn[i] <= N) {
				sum += Kn[i];
				temp.push_back(vn[i]);
				DFS(i, sum);
				sum -= Kn[i];
				temp.pop_back();
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &K, &P);
	int num;
	for (int i = sqrt((double)N); i > 0; i--) {
		vn.push_back(i);
		num = 1;
		for (int j = 0; j < P; j++) 
			num *= i;
		Kn.push_back(num);
	}
	DFS(0, 0);
	if (answer.size() == 0) printf("Impossible\n");
	else {
		printf("%d = ", N);
		for (int i = 0; i < answer.size(); i++) {
			if (i == 0) printf("%d^%d", answer[i], P);
			else printf(" + %d^%d", answer[i], P);
		} 
	}
	return 0;
}