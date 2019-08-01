#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct stu
{
	int tall;
	char name[9];
};

bool cmp(stu a, stu b) {
	if (a.tall == b.tall)
		return strcmp(a.name, b.name) < 0;
	return a.tall > b.tall;
}

void display(stu stus[] ,int start,int m) {
	if (m == 1) {
		printf("%s\n", stus[start].name);
	}
	else
	{
		int v;
		if (m % 2 == 0)
			v = m - 1;
		else
			v = m - 2;
		for (int i = v; i > 0; i -= 2) {
			if (i != v)
				printf(" %s", stus[start + i].name);
			else
				printf("%s", stus[start + i].name);
		}
		for (int i = 0; i < m; i += 2) {
			printf(" %s", stus[start + i].name);
		}
		printf("\n");
	}
}

int main() {
	int N, K,m,m1,start;
	scanf("%d%d", &N, &K);
	stu *stus = new stu[N];
	for (int i = 0; i < N; i++) {
		scanf("%s", stus[i].name);
		scanf("%d", &stus[i].tall);
	}
	sort(stus, stus + N, cmp);
	m = N / K;
	m1 = m + N % K;
	start = 0;
	display(stus, start, m1);
	start += m1;
	while (start < N) {
		display(stus, start, m);
		start += m;
	}
	return 0;
}