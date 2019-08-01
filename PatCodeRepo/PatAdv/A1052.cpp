#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define maxn 100010

struct node {
	int address;
	int key;
	int next;
}nodes[maxn];

bool cmp(node a, node b) {
    return a.key < b.key;
}

int main() {
	int N, start;
	scanf("%d%d", &N, &start);
	//¿ÕÁ´±í
	if (start == -1) {
		printf("0 -1\n");
		return 0;
	}

	node temp;
	vector<node> v;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &temp.address,&temp.key,&temp.next);
		nodes[temp.address].address = temp.address;
		nodes[temp.address].key = temp.key;
		nodes[temp.address].next = temp.next;
	}


	while (start != -1) {
		v.push_back(nodes[start]);
		start = nodes[start].next;
	}
	//¿ÕÁ´±í
	if (v.size() == 0) {
		printf("0 -1");
		return 0;
	}
	sort(v.begin(), v.end(), cmp);
	printf("%d %05d\n", v.size(), v[0].address);
	for (int i = 0; i < v.size() - 1; i++) {
		printf("%05d %d %05d\n", v[i].address, v[i].key, v[i + 1].address);
	}
	if(v.size()>=1)
    	printf("%05d %d -1", v[v.size() - 1].address, v[v.size() - 1].key);
	return 0;
}