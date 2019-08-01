#include<cstdio>
#include<iostream>
using namespace std;

#define max 1010

int main() {
	char str[max];
	cin.getline(str,max);
	int a[26] = { 0 },t1,t2,m;
	for (int i = 0; i < max; i++) {
		if (str[i] == '\0')
			break;
		t1 = str[i] - 'a';
		t2 = str[i] - 'A';
		if (t1 >= 0 && t1 < 26)
			a[t1]++;
		else if(t2 >= 0 && t2 < 26)
			a[t2]++;
	}
	m = 0;
	for (int i = 0; i < 26; i++) {
		if (a[i] > m)
			m = a[i];
	}
	for (int i = 0; i < 26; i++) {
		if (a[i] == m) {
			printf("%c ", 'a' + i);
			break;
		}
	}
	printf("%d\n", m);
	return 0;
}