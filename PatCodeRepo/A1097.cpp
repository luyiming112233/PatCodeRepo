#include<cstdio>
#include<vector>
#include<set>
using namespace std;

#define maxn 100010

struct node {
	int address;
	int key;
	int next;
}nodes[maxn];

void printList(vector<node> v) {
	if (v.size() == 0)
		return;
	for (int i = 0; i < v.size() - 1; i++) {
		printf("%05d %d %05d\n", v[i].address, v[i].key, v[i + 1].address);
	}
	if(v.size()!=0)
		printf("%05d %d -1\n", v[v.size()-1].address, v[v.size() - 1].key);
}

int main() {
	int start, N;
	node temp;
	vector<node> list, l1, l2;
	set<int> s;
	int value;
	scanf("%d %d", &start, &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &temp.address,&temp.key,&temp.next);
		if(temp.address>=0 && temp.address <= 1e5)
		    nodes[temp.address] = temp;
	}
	while (start != -1) {
		list.push_back(nodes[start]);
		start = nodes[start].next;
	}
	for (int i = 0; i < list.size(); i++) {
		value = list[i].key;
		if (value < 0)
			value = -value;
		//没有找到，第一次出现
		if (s.find(value) == s.end()) {
			s.insert(value);
			l1.push_back(list[i]);
		}
		else {
			l2.push_back(list[i]);
		}
	}
	printList(l1);
	printList(l2);
	return 0;
}
