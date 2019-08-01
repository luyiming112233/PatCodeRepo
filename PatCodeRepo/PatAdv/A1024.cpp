#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 15

bool judge(vector<int> v) {
	for (int i = 0; i < v.size() / 2; i++) {
		if (v[i] != v[v.size() - 1 - i])
			return false;
	}
	return true;
}

void add(vector<int> &a) {
	vector<int> b;
	b.assign(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int add = 0,temp;
	for (int i = 0; i < a.size(); i++) {
		temp = a[i] + b[i] + add;
		add = temp / 10;
		a[i] = temp % 10;
	}
	if (add > 0)
		a.push_back(add);
	reverse(a.begin(), a.end());
	
}

int main() {
	char str[maxn];
	int K,step=0;
	vector<int> a,b;
	scanf("%s", str);
	scanf("%d", &K);
	for (int i = 0; i < maxn; i++) {
		if (str[i] == '\0')
			break;
		a.push_back(str[i] - '0');
	}
	for (step = 0; step < K; step++) {
		if (judge(a)) {
			break;
		}
		add(a);
	}
	for (int i = 0; i < a.size(); i++) {
		printf("%d", a[i]);
	}
	printf("\n%d", step);

}