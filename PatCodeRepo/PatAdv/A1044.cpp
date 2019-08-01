#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

struct cut {
	int first;
	int end;
};

int main() {
	int N, M,sum=0,num, mincost=2e8;
	cut temp;
	temp.first = 1;
	temp.end = 0;
	queue<int> q;
	vector<cut> v;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		q.push(num);
		temp.end++;
		sum += num;
		while (sum >= M) {
			if (sum < mincost) {
				mincost = sum;
				v.clear();
				v.push_back(temp);
			}
			else if (sum == mincost) {
				v.push_back(temp);
			}
			sum -= q.front();
			q.pop();
			temp.first++;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		printf("%d-%d\n", v[i].first, v[i].end);
	}
	return 0;
}