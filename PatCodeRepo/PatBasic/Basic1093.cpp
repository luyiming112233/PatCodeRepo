#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

#define ssize 1000010

int main() {
	int a[127] = { 0 };
	vector<char> v;
	char str[ssize];
	cin.getline(str, ssize);
	for (int i = 0; i < ssize; i++) {
		if (str[i] == '\0')
			break;
		if (a[str[i]] == 0) {
			a[str[i]]++;
			v.push_back(str[i]);
		}
	}
	cin.getline(str, ssize);
	for (int i = 0; i < ssize; i++) {
		if (str[i] == '\0')
			break;
		if (a[str[i]] == 0) {
			a[str[i]]++;
			v.push_back(str[i]);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		printf("%c", v[i]);
	}
	printf("\n");
	return 0;
}