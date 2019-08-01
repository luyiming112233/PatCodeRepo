#include<cstdio>
#include<vector>
using namespace std;

int main() {
	int N, M,id,num,stu_num=0,thing_num=0;
	int thing[10010] = { 0 };
	char name[5];
	vector<int> v;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &id);
		thing[id] = 1;
	}
	for (int i = 0; i < N; i++) {
		scanf("%s", name);
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			scanf("%d", &id);
			if (thing[id] == 1) {
				v.push_back(id);
			}
		}
		if (v.size() != 0) {
			stu_num++;
			printf("%s:", name);
			for (int k = 0; k < v.size(); k++) {
				printf(" %04d", v[k]);
				thing_num++;
			}
			printf("\n");
		}
		v.clear();
	}
	printf("%d %d\n", stu_num, thing_num);
	return 0;
}