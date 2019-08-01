#include<cstdio>
#include<iostream>
#include<string.h>
#include<string>
#include<map>
using namespace std;

#define maxn 1048580
#define NOC '?'

char str[maxn];
char temp[maxn];

char judge(char c) {
	if (c >= '0' && c <= '9')
		return c;
	if (c >= 'a' && c <= 'z')
		return c;
	if (c >= 'A' && c <= 'Z')
		return c-'A'+'a';
	return NOC;
}

int main() {
	cin.getline(str, maxn);
	map<string, int> m;
	map<string, int>::iterator it;
	string answer;
	int num=0;
	int len=0;
	char c;
	for (int i = 0; i < maxn; i++) {
		c = judge(str[i]);
		if (c==NOC) {
			if (len > 0) {
				temp[len] = '\0';
				it = m.find(temp);
				if (it == m.end()) {
					m[temp] = 1;
				}
				else {
					it->second++;
				}
				len = 0;
			}
			if (str[i] == '\0')
				break;
		}
		else {
			temp[len] = c;
			len++;
		}
		
	}
	for (it = m.begin(); it != m.end(); it++) {
		if (it->second > num) {
			num = it->second;
			answer = it->first;
		}
	}
	printf("%s %d", answer.c_str(), num);
	return 0;
}