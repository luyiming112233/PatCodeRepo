#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define ssize 1010

bool palindromic(vector<int> v) {
	for (int i = 0; i < v.size() / 2; i++) {
		if (v[i] != v[v.size() - 1 - i])
			return false;
	}
	return true;
}

void vprint(vector<int> v) {
	for (int i = 0; i < v.size(); i++)
		printf("%d", v[i]);
}

int main() {
	int time,temp,off;
	char n[ssize];
	vector<int> v,v2;
	while (~scanf("%s", n)) {
		for (int i = 0; i < ssize; i++) {
			if (n[i] == '\0')
				break;
			v.push_back(n[i]-'0');
		}
		if (palindromic(v)) {
			vprint(v);
			printf(" is a palindromic number.\n");
		}
		else {
			time = 10;
			while (true) {
				v2.assign(v.begin(), v.end());
				reverse(v2.begin(), v2.end());
				vprint(v);
				printf(" + ");
				vprint(v2);
				printf(" = ");
				off = 0;
				for (int i = 0; i < v.size(); i++) {
					temp = (v[i] + v2[i] + off) % 10;
					off = (v[i] + v2[i] + off) / 10;
					v[i] = temp;
				}
				if (off > 0)
					v.push_back(off);
				reverse(v.begin(), v.end());
				vprint(v);
				printf("\n");
				if (palindromic(v)) {
					vprint(v);
					printf(" is a palindromic number.\n");
					break;
				}
				time--;
				if (time ==0 ) {
					printf("Not found in 10 iterations.\n");
					break;
				}
				v2.clear();
			}
		}
		v.clear();
	}
	return 0;
}