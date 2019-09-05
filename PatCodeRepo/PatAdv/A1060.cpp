#include<cstdio>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
#define slen 200
string fun(char *str, int &index, vector<int> &v, int &k, int N) {
	int t = 0, fn0;
	char s[slen];
	s[0] = '-';
	index = -1;
	for (int i = 0; i < slen; i++) {
		if (str[i] == '\0') {
			if (index == -1) index = i;
			break;
		}
		if (str[i] == '.') index = i;
		else v[t++] = str[i] - '0';
	}
	fn0 = index;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != 0) {
			for (int j = 0; j < N; j++) {
				s[j] = v[i + j] + '0';
				s[j + 1] = '\0';
			}
			fn0 = i;
			break;
		}
	}
	k = index - fn0;
	return s;
}
void printNum(string n, int k, int N) {
	if (N == 0) {
		printf("0*10^%d", k);
	}
	else if (n[0] == '-') {
		printf("0.");
		for (int i = 0; i < N; i++) printf("0");
		printf("*10^0");
	}
	else printf("0.%s*10^%d", n.c_str(), k);
}
int main() {
	int N, indexa, indexb, ka, kb;
	char sa[slen], sb[slen];
	vector<int> a, b;
	for (int i = 0; i < slen; i++) {
		a.push_back(0);
		b.push_back(0);
	}
	scanf("%d %s %s", &N, sa, sb);
	string na = fun(sa, indexa, a, ka, N);
	string nb = fun(sb, indexb, b, kb, N);
	if (na == nb && ka == kb) {
		printf("YES ");
		printNum(na, ka, N);
	}
	else {
		printf("NO ");
		printNum(na, ka, N);
		printf(" ");
		printNum(nb, kb, N);
	}
	return 0;
}
