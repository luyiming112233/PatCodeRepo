#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

#define maxn 10010

struct family {
	int id, num;
	double area, estate;
	double AvgArea, AvgEst;
	family() {
		id = 0, num = 0, area=0, estate = 0;
	}
}ftemp;

bool cmp(family a,family b) {
	if (a.AvgArea != b.AvgArea) return a.AvgArea > b.AvgArea;
	return a.id < b.id;
}

double Area[maxn] = { 0 }, Estate[maxn] = { 0 };
int parent[maxn];//³õÊ¼»¯

int getParent(int root) {
	int temp = root;
	while (parent[temp] != temp)
		temp = parent[temp];
	while (parent[root] != root) {
		int c = parent[root];
		parent[root] = temp;
		root = c;
	}
	return root;
}

void Union(int a,int b) {
	int pa = getParent(a), pb = getParent(b);
	if (pa == pb) return;
	if (pa < pb) {
		parent[pb] = pa;
	}
	else {
		parent[pa] = pb;
	}
}

int main() {
	int N,id,fa,mo,k,kid;
	set<int> s;
	set<int>::iterator sit;
	map<int, family> m;
	map<int, family>::iterator mit;
	vector<family> v;
	for (int i = 0; i < maxn; i++) parent[i] = i;
	scanf("%d", &N);
	for (int ni = 0; ni < N; ni++) {
		scanf("%d %d %d %d", &id, &fa, &mo, &k);
		s.insert(id);
		if (fa != -1) {
			Union(id, fa);
			s.insert(fa);
		}
		if (mo != -1) {
			Union(id, mo);
			s.insert(mo);
		}
		for (int i = 0; i < k; i++) {
			scanf("%d", &kid);
			Union(id, kid);
			s.insert(kid);
		}
		scanf("%lf %lf", &Estate[id], &Area[id]);
	}
	for (sit = s.begin(); sit != s.end(); sit++) {
		int pa = getParent(*sit);
		mit = m.find(pa);
		if (mit == m.end()) {
			m[pa] = ftemp;
			mit = m.find(pa);
			mit->second.id = pa;
		}
		mit->second.area += Area[*sit];
		mit->second.estate += Estate[*sit];
		mit->second.num++;
	}
	for (mit = m.begin(); mit != m.end(); mit++) {
		mit->second.AvgArea = mit->second.area / mit->second.num;
		mit->second.AvgEst = mit->second.estate / mit->second.num;
		v.push_back(mit->second);
	}
	sort(v.begin(), v.end(), cmp);
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) 
		printf("%04d %d %.3f %.3f\n", v[i].id, v[i].num, v[i].AvgEst, v[i].AvgArea);
	return 0;
}