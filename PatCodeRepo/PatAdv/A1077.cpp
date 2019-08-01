#include<cstdio>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;

#define maxn 260

int main() {
	char str[maxn];
	string s;
	int N,len,tlen,minL=maxn;
	scanf("%d\n", &N);
	vector<char> v;
	for (int i = 0; i < N; i++) {
		cin.getline(str, maxn);
		s = str;
		if (i == 0) {
			for (int j = s.length() - 1; j >= 0; j--) {
				v.push_back(s[j]);
			}
		}
		else {
			len = v.size();
			if (len > s.length()) {
				len = s.length();
			}
			for (tlen = 0; tlen < len; tlen++) {
				if (v[tlen] != s[s.length() - 1 - tlen])
					break;
			}
			if (tlen < minL) {
				minL = tlen;
			}
		}
	}
	if (minL == 0)
		printf("nai");
	else {
		for (int i = minL - 1; i >= 0; i--)
			printf("%c", v[i]);
	}
}