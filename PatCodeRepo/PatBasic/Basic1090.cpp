#include<cstdio>
#include<vector>

using namespace std;

#define ssize 100010
#define gsize 1010

int main() {
	vector<vector<int> > v(ssize);
	int N, M, K,a,b,thing[ssize],G[gsize];
	bool OK;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &K);
		for (int k = 0; k < K; k++)
			scanf("%d", &G[k]);
		//��ʼ��thing����
		for (int t = 0; t < ssize; t++)
			thing[t] = 0;
		OK = true;
		for(int k=0;k<K&&OK;k++){
			//˵������Ʒ����ͻ
			if (thing[G[k]] == 0) {
				//������ͻ���
				for (int c = 0; c < v[G[k]].size(); c++)
					thing[v[G[k]][c]] = 1;
			}
			else {
				OK = false;
			}
		}
		if (OK)
			printf("Yes\n");
		else
			printf("No\n");
	}
}