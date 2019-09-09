#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 110

struct p {
	int a, b;
};

int say[maxn];

bool cmp(p p1, p p2) {
	if (p1.a != p2.a)
		return p1.a < p2.a;
	return p1.b < p2.b;
}

int main() {
	int N,lie1,lie2;
	vector<p> answer;
	p temp;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &say[i]);
	}
	for (int wi = 1; wi <= N; wi++) {
		for (int wj = wi + 1; wj <= N; wj++) {
			lie1 = 0, lie2 = 0;
			for (int i = 1; i <= N; i++) {
				if (say[i] < 0) {
					//说谎
					if (-say[i] != wi && -say[i] != wj) {
						//狼人说谎
						if (i == wi || i == wj)
							lie1++;
						//好人说谎
						else
							lie2++;
					}
				}
				else {
					//说谎
					if (say[i] == wi || say[i] == wj) {
						//狼人说谎
						if (i == wi || i == wj)
							lie1++;
						//好人说谎
						else
							lie2++;
					}
				}
			}
			if (lie1 == 1 && lie2 == 1) {
				temp.a = wi, temp.b = wj;
				answer.push_back(temp);
			}
		}
	}
	if (answer.size() == 0)
		printf("No Solution");
	else {
		sort(answer.begin(), answer.end(), cmp);
		printf("%d %d", answer[0].a, answer[0].b);
	}
	return 0;
}