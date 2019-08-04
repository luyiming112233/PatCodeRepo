#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

#define maxn 90

int main() {
	vector<char> v;
	set<char> s;
	char str[maxn];
	cin.getline(str, maxn);
	for (int i = 0; i < maxn; i++) {
		if (str[i] == '\0')
			break;
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] += ('A' - 'a');
		}
		if (s.find(str[i]) == s.end()) {
			s.insert(str[i]);
			v.push_back(str[i]);
		}
	}
	cin.getline(str, maxn);
	for (int i = 0; i < maxn; i++) {
		if (str[i] == '\0')
			break;
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] += ('A' - 'a');
		}
		s.erase(str[i]);
	}
	for (int i = 0; i < v.size(); i++) {
		if (s.find(v[i]) != s.end()) {
			printf("%c", v[i]);
		}
	}
	return 0;
}
