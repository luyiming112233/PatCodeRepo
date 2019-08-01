#include<cstdio>
#include<iostream>
using namespace std;

#define maxn 130
#define maxlen 10010

int main() {
	int a[maxn] = { 0 };
	char S1[maxlen], S2[maxlen];
	cin.getline(S1, maxlen);
	cin.getline(S2, maxlen);
	for (int i = 0; i < maxlen; i++) {
		if (S2[i] == '\0')
			break;
		a[S2[i]] = 1;
	}
	for (int i = 0; i < maxlen; i++) {
		if (S1[i] == '\0')
			break;
		if (a[S1[i]] == 0)
			printf("%c", S1[i]);
	}
	return 0;
}