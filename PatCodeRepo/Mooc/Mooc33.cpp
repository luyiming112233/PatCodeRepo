#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

#define maxn 1010

vector<int> v;
vector<int> mat[maxn];
int degree[maxn] = { -1 },N;

void hashfind(int index) {
	int d = 0;
	int num = v[index];
	if (num < 0) return;
	int key = num % N;
	while (v[key] != num) {
		mat[key].push_back(index);
		key = (key + 1) % N;
		d++;
	}
	degree[index] = d;
}

int main() {
	int num,size=0;
	vector<int> answer;
	fill(degree, degree + maxn, -1);
	set<int> s;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		v.push_back(num);
		if (num >= 0)
			size++;
	}
	for (int i = 0; i < N; i++)
		hashfind(i);
	for (; size > 0; size--) {
		int minN = 1000000000;
		int minIndex = -1;
		for (int i = 0; i < N; i++) {
			if(degree[i]==0 && minN > v[i]){
				minN = v[i];
				minIndex = i;
			}
		}
		degree[minIndex] = -1;
		answer.push_back(minN);
		for (int i = 0; i < mat[minIndex].size(); i++) 
			degree[mat[minIndex][i]]--;
	}
	for (int i = 0; i < answer.size(); i++) {
		if (i == 0)
			printf("%d", answer[i]);
		else
			printf(" %d", answer[i]);
	}
	return 0;
}