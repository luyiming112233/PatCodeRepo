#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 300

vector<char> trans(char *str) {
	vector<char> v;
	for (int i = 0; i < maxn; i++) {
		if (str[i] == '\0')
			break;
		v.push_back(str[i]);
	}
	reverse(v.begin(), v.end());
	return v;
}

vector<char> compare(vector<char> a, vector<char> b) {
	vector<char> c;
	int len = a.size();
	if (len > b.size())
		len = b.size();
	for (int i = 0; i < len; i++) {
		if (a[i] == b[i])
			c.push_back(a[i]);
		else
			break;
	}
	return c;
}

int main() {
	vector<char> a, b, c;
	int N;
	char str[maxn];
	scanf("%d\n", &N);
	cin.getline(str, maxn);
	c = trans(str);
	for (int i = 1; i < N; i++) {
		cin.getline(str, maxn);
		a = c;
		b = trans(str);
		c = compare(a, b);
	}
	if (c.size() == 0)
		printf("nai");
	else {
		reverse(c.begin(), c.end());
		for (int i = 0; i < c.size(); i++)
			printf("%c", c[i]);
	}
	return 0;
}