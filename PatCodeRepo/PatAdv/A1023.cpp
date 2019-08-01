#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 25

int main() {
	char str[maxn];
	vector<int> v,v2;
	int num[10] = { 0 },add=0;
	bool flag = true;
	scanf("%s", str);
	for (int i = 0; i < maxn; i++) {
		if (str[i] == '\0')
			break;
		v.push_back(str[i] - '0');
		num[str[i] - '0']++;
	}
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		v[i] = v[i] * 2 + add;
		add = v[i] / 10;
		v2.push_back(v[i] % 10);
	}
	if (add == 1)
		v2.push_back(add);
	for (int i = 0; i < v2.size(); i++) {
		num[v2[i]]--;
	}
	for (int i = 0; i < 10; i++) {
		if (num[i] != 0) {
			flag = false;
			break;
		}
	}
	if (flag)
		printf("Yes\n");
	else
		printf("No\n");
	for (int i = v2.size() - 1; i >= 0; i--)
		printf("%d",v2[i]);
	return 0;
}