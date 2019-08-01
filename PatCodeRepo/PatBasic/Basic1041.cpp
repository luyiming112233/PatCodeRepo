#include<cstdio>
#include<cstring>
#define max 1010

struct stu
{
	int jishi;
	int kaoshi;
	char card[17];
}stus[max];

int main() {
	int n,m,d;
	scanf("%d", &n);
	struct stu temp;
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d", &temp.card, &temp.jishi, &temp.kaoshi);
		stus[temp.jishi].jishi = temp.jishi;
		stus[temp.jishi].kaoshi = temp.kaoshi;
		strcpy(stus[temp.jishi].card, temp.card);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &d);
		printf("%s %d\n", stus[d].card, stus[d].kaoshi);
	}
	return 0;
}