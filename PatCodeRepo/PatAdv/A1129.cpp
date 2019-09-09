#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define maxn 50010

int frq[maxn] = { 0 };

struct node {
	int key;
	int num;
};

bool cmp(node a, node b) {
	if (a.num != b.num)
		return a.num > b.num;
	return a.key < b.key;
}

vector<node> v;
int N, K;

void vectorinit() {
	node temp;
	temp.key = -1;
	for (int i = 0; i < K; i++) {
		temp.num = -1-i;
		v.push_back(temp);
	}
}

void vdisplay(int num) {
	printf("%d:", num);
	for (int i = 0; i < v.size(); i++) {
		if (v[i].num > 0)
			printf(" %d", v[i].key);
	}
	printf("\n");
}

bool judge(int ff,int value) {
	if (ff > v.back().num)
		return true;
	if (ff == v.back().num &&value < v.back().key) {
		return true;
	}
	return false;
}

void vinsert(int num) {
	frq[num]++;
	if (judge(frq[num],num)) {
		int index = -1;
		for (int i = 0; i < K; i++) {
			if (v[i].key == num) {
				index = i;
				break;
			}
		}
		if (index == -1) {
			v[K - 1].num = frq[num];
			v[K - 1].key = num;
		}
		else {
			v[index].num++;
		}
		sort(v.begin(), v.end(), cmp);
	}
}

int main() {
	scanf("%d %d", &N, &K);
	vectorinit();
	int num;
	scanf("%d", &num);
	vinsert(num);
	for (int i = 1; i < N; i++) {
		scanf("%d", &num);
		vdisplay(num);
		vinsert(num);
	}
	return 0;
}