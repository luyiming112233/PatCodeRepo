#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N, M,tea,stu,sum;
	scanf("%d %d", &N, &M);
	vector<int> v;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tea);
		for (int j = 0; j < N - 1; j++) {
			scanf("%d", &stu);
			if (stu >= 0 && stu <= M)
				v.push_back(stu);
		}
		sum = 0;
		sort(v.begin(), v.end());
		for (int j = 1; j < v.size() - 1; j++) {
			sum += v[j];
		}
		sum = (sum + tea * (v.size() - 2))*10;
		sum /= (2 * (v.size() - 2));
		if (sum % 10 >= 5)
			sum += 10;
		sum /= 10;
		printf("%d\n", sum);
		v.clear();
	}
	return 0;
}