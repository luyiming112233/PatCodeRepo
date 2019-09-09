#include<cstdio>
#include<map>
using namespace std;

int main() {
	int N,num,size,E=0;
	map<int, int> m;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		if (m.find(num) == m.end())
			m[num] = 1;
		else {
			m[num]++;
		}
	}
	size = N;
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		size -= it->second;
		if (it->first <= size) {
			E = it->first;
		}
		else {
			E = it->first - 1;
			break;
		}
	}
	printf("%d", E);
	return 0;
}