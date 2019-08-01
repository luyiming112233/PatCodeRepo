#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct p{
	int id;
	int dis;
};

bool cmp(p a, p b) {
	return a.dis < b.dis;
}

int main() {
	int N,x,y,id;
	p temp;
	vector<p> v;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &id, &x, &y);
		temp.id = id;
		temp.dis = x * x + y * y;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), cmp);
	printf("%04d %04d\n", v[0].id, v[v.size() - 1].id);
	return 0;
}