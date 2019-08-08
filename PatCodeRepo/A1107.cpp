#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>

using namespace std;

#define maxn 1010

vector<int> peo[maxn];//һ���˶�Ӧ��hobby
vector<int> hobby[maxn];//һ��hobby��Ӧ����Ⱥ
bool scan[maxn] = { false };

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int N,hnum,ho,hid,pid;
	set<int> s;
	vector<int> clu;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d:", &hnum);
		for (int j = 0; j < hnum; j++) {
			scanf("%d", &ho);
			peo[i].push_back(ho);
			hobby[ho].push_back(i);
		}
	}
	for (int i = 1; i < maxn; i++) {
		if (scan[i] == true)
			continue;
		queue<int> qh;
		s.clear();
		qh.push(i);
		scan[i] = true;
		while (!qh.empty()) {
			hid = qh.front();
			qh.pop();
			for (int j = 0; j < hobby[hid].size(); j++) {
				pid = hobby[hid][j];
				//���û���ҵ���ʾ������
				if (s.find(pid) == s.end()) {
					s.insert(pid);
					//���pid��Ӧ�İ���
					for (int k = 0; k < peo[pid].size(); k++) {
						if (scan[peo[pid][k]] == false) {
							scan[peo[pid][k]] = true;
							qh.push(peo[pid][k]);
						}
					}
				}
			}
		}
		if (s.size() != 0)
			clu.push_back(s.size());
	}
	sort(clu.begin(), clu.end(), cmp);
	printf("%d\n", clu.size());
	for (int i = 0; i < clu.size(); i++) {
		if (i == 0)
			printf("%d", clu[i]);
		else
			printf(" %d", clu[i]);
	}
	return 0;
}