#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

using namespace std;

#define ssize 5

vector<vector<int> > v;
map<string, int> m;
int tvid = 0;

bool judge(char name[]) {
	int len;
	for (len = 0; len < ssize; len++) {
		if (name[len] == '\0')
			break;
	}
	if (len != 4)
		return false;
	if (name[0] < 'A' || name[0]>'Z')
		return false;
	if (name[1] < 'A' || name[1]>'Z')
		return false;
	if (name[2] < 'A' || name[2]>'Z')
		return false;
	if (name[3] < '0' || name[3]>'9')
		return false;
	return true;
}

int getVid() {
	return tvid++;
}

int main() {
	int N, K,num,cid;
	char name[ssize];
	map<string, int>::iterator it;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &cid, &num);
		for (int j = 0; j < num; j++) {
			scanf("%s", name);
			if (judge(name) == false)
				continue;
			it = m.find(name);
			if (it == m.end()) {
				m[name] = getVid();
				vector<int> temp;
				temp.push_back(cid);
				v.push_back(temp);
			}
			else {
				v[it->second].push_back(cid);
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		sort(v[i].begin(), v[i].end());
	}
	for (int i = 0; i < N; i++) {
		scanf("%s", name);
		it = m.find(name);
		if (it == m.end()) {
			printf("%s 0\n", name);
		}
		else {
			printf("%s", name);
			printf(" %d", v[it->second].size());
			for (int j = 0; j < v[it->second].size(); j++) {
				printf(" %d", v[it->second][j]);
			}
			printf("\n");
		}
	}
	return 0;
}