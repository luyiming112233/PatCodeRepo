#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define nsize 100010

int K;

struct node {
	int v;
	int id;
	int next;
	int index;
}nodes[nsize];

bool cmp(node a, node b) {
	int an, bn;
	if (a.v < 0) {
		an = 1;
	}
	else if (a.v <= K)
		an = 2;
	else
		an = 3;
	if (b.v < 0) {
		bn = 1;
	}
	else if (b.v <= K)
		bn = 2;
	else
		bn = 3;
	if (an != bn) {
		return an < bn;
	}
	else
		return a.index < b.index;
}

int main() {
	int first, N;
	vector<node> v;
	node temp;
	scanf("%d %d %d", &first, &N, &K);
	for (int i = 0; i < nsize; i++)
		nodes[i].id = -1;

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &temp.id, &temp.v, &temp.next);
		nodes[temp.id].id = temp.id;
		nodes[temp.id].v = temp.v;
		nodes[temp.id].next = temp.next;
	}
	while (first!=-1){
		if (nodes[first].id == -1)
			break;
		v.push_back(nodes[first]);
		first = nodes[first].next;
	}
	for (int i = 0; i < v.size(); i++)
		v[i].index = i;
	sort(v.begin(), v.end(),cmp);
	for (int i = 0; i < v.size() - 1 &&v.size()>0; i++) {
		printf("%05d %d %05d\n", v[i].id, v[i].v, v[i + 1].id);
	}
	if(v.size()>0)
    	printf("%05d %d -1\n", v[v.size()-1].id, v[v.size() - 1].v);
	return 0;
}