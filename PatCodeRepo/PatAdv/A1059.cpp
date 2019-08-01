#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

//判断从2开始的奇数
bool isPrime(int n) {
	for (int i = 2; i*i < n; i++) {
		if (n%i == 0)
			return false;
	}
	return true;
}

int main() {
	int N,temp,nn,vv;
	scanf("%d", &N);
	//如果自己是奇数
	if (isPrime(N)) {
		printf("%d=%d", N, N);
		return 0;
	}
	vector<int> answer;
	map<int, int> m;
	temp = N;
	int s = 2;
	while (true) {
		if (temp%s == 0 && isPrime(s)) {
			answer.push_back(s);
			temp /= s;
		}
		else {
			s++;
		}
		if (temp == 1)
			break;
	}
	temp = -1;
	nn = 1;
	for (int i = 0; i < answer.size(); i++) {
		if (answer[i] == temp) {
			nn++;
		}
		else {
			m[temp] = nn;
			nn = 1;
			temp = answer[i];
		}
	}
	m[temp] = nn;
	printf("%d=", N);
	vv = 0;
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		vv++;
		if (vv>2)
			printf("*");
		if (it->first == -1)
			continue;
		if (it->second > 1) {
			printf("%d^%d", it->first, it->second);
		}
		else {
			printf("%d", it->first);
		}
	}
	return 0;
}