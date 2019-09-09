#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 10010
#define slen 8

struct pa {
	int a;
	int b;
};

bool cmp(pa p1, pa p2) {
	if (p1.a != p2.a)
		return p1.a < p2.a;
	return p1.b < p2.b;
}

vector<int> v[maxn];
int gender[maxn] = { 0 };

int read() {
	char str[slen];
	scanf("%s", str);
	int num;
	sscanf(str, "%d", &num);
	if (str[0] == '-') {
		num = -num;
		gender[num] = -1;
	}
	else {
		gender[num] = 1;
	}
	return num;
}

int main() {
	int N, M,K,a,b;
	pa temp;
	vector<pa> answer;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		a = read();
		b = read();
		v[a].push_back(b);
		v[b].push_back(a);
	}
	scanf("%d", &K);
	for (int ki = 0; ki < K; ki++) {
		scanf("%d %d", &a, &b);
		vector<int> fa, fb;
		answer.clear();
		if (a < 0)
			a = -a;
		if (b < 0)
			b = -b;
		for (int i = 0; i < v[a].size(); i++) 
			if (gender[v[a][i]] == gender[a] && v[a][i]!=b)
				fa.push_back(v[a][i]);
		for (int i = 0; i < v[b].size(); i++)
			if (gender[v[b][i]] == gender[b] && v[b][i]!=a) 
				fb.push_back(v[b][i]);
		for (int i = 0; i < fa.size(); i++) {
			int aid = fa[i];
			for (int j = 0; j < fb.size(); j++) {
				int bid = fb[j];
				bool flag = false;
				for (int ai = 0; ai < v[aid].size(); ai++) {
					if (v[aid][ai] == bid) {
						flag = true;
						break;
					}
				}
				if (flag) {
					temp.a = aid;
					temp.b = bid;
					answer.push_back(temp);
				}
			}
		}
		sort(answer.begin(), answer.end(), cmp);
		printf("%d\n", answer.size());
		for (int i = 0; i < answer.size(); i++) {
			printf("%04d %04d\n", answer[i].a, answer[i].b);
		}
	}
	return 0;
}