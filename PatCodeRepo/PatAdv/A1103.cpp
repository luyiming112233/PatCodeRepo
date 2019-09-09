#include<cstdio>
#include<vector>
using namespace std;

#define maxn 410

vector<int> v;
vector<int> t;
vector<int> answer;
int N, K, P, temp, M;
int sum = 0,maxs=0;
bool flag = false;


void deep(int id) {
	if (id > 0 && id <= K) {
		sum += v[t[id]];
	}
	if (id == K) {
		if (sum == N) {
			flag = true;
			int tsum = 0;
			for (int i = 1; i <t.size(); i++) {
				tsum += t[i];
			}
			if (tsum > maxs) {
				maxs = tsum;
				answer = t;
			}
		}
	}
	if (id >= 0 && id < K) {
		for (int i = t[id]; i > 0; i--) {
			if (sum + v[i] <= N) {
				t.push_back(i);
				deep(id + 1);
				t.pop_back();
			}
		}
	}
	if (id > 0 && id <= K) {
		sum -= v[t[id]];
	}
}

int main() {
	scanf("%d %d %d", &N, &K, &P);
	for (int i = 0; i <= N; i++) {
		temp = i;
		for (int j = 1; j < P; j++) {
			temp *= i;
		}
		if (temp > N) {
			break;
		}
		else {
			v.push_back(temp);
		}
	}
	M = v.size()-1;
	t.push_back(M);
	deep(0);
	if (flag) {
		printf("%d", N);
		for (int i = 1; i <= K; i++) {
			if (i == 1) {
				printf(" = %d^%d", answer[i], P);
			}
			else {
				printf(" + %d^%d", answer[i], P);
			}
		}
	}
	else {
		printf("Impossible");
	}
	return 0;

}
