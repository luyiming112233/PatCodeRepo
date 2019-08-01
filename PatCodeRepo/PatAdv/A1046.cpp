#include<cstdio>
#include<vector>
using namespace std;

int main() {
	int N, M, sum=0,dis,start,end,len,temp;
	vector<int> v;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &dis);
		sum += dis;
		v.push_back(dis);
	}
	for (int i = 0; i < N; i++) {
		v.push_back(v[i]);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &start, &end);
		start--;
		end--;
		temp = end - start;
		if (temp < 0)
			temp = -temp;
		if (temp > N - temp) {
			temp = start;
			start = end;
			end = temp;
		}
		if (end < start)
			end += N;
		len = 0;
		for (int j = start; j<end; j++) {
			len += v[j];
		}
		if (len > sum - len)
			len = sum - len;
		printf("%d\n", len);
	}
	return 0;
}