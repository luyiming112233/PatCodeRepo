#include<cstdio>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>

using namespace std;

#define maxn 10

bool isZore(char num[]) {
	for (int i = 0; i < maxn; i++) {
		if (num[i] == '\0')
			break;
		if (num[i] != '0')
			return true;
	}
	return false;
}

bool cmp(string a, string b) {
	return a+b<b+a;
}

int main() {
	int N,start;
	vector<string> v,vzero;
	char num[maxn],temp[maxn];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", num);
		//Ìø¹ýÈ«0
		if (isZore(num)) {
			v.push_back(num);
		}
		else {
			vzero.push_back(num);
		}
	}
	sort(v.begin(), v.end(), cmp);
	if (v.size() == 0) {
		printf("0");
		return 0;
	}
	for (int i = 0; i < v.size(); i++) {
		if (i == 0) {
			int tfirst;
			for (tfirst = 0; tfirst < maxn; tfirst++) {
				if (v[i][tfirst] != '0')
					break;
			}
			printf("%s",v[i].substr(tfirst).c_str());
			for (int j = 0; j < vzero.size(); j++) {
				printf("%s", vzero[i].c_str());
			}
		}
		else {
			printf("%s", v[i].c_str());
		}
	}
	return 0;
}