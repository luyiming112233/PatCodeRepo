#include<cstdio>
#include<vector>
#include<set>
using namespace std;

#define maxn 1010

int main() {
	int k;
	vector<char> v;
	set<char> s;
	char str[maxn];
	scanf("%d\n", &k);
	scanf("%s", str);
	for (int i = 0; i < maxn; i++) {
		if (str[i] == '\0')
			break;
		if (s.find(str[i]) == s.end()) {
			s.insert(str[i]);
			v.push_back(str[i]);
		}
	}
	char temp='#';
	int num=0;
	for (int i = 0; i < maxn; i++) {
		if (str[i] != temp) {
			if (num != k) {
				s.erase(temp);
			}
			temp = str[i];
			num = 1;
		}
		else {
			if (num == k)
				num = 1;
			else
    			num++;
		}
		if (str[i] == '\0')
			break;
	}
	for (int i = 0; i < v.size(); i++) {
		if (s.find(v[i]) != s.end())
			printf("%c", v[i]);
	}
	printf("\n");
	temp = '#';
	num = 0;
	for (int i = 0; i < maxn; i++) {
		if (s.find(str[i]) == s.end()) {
			if (str[i] == '\0')
				break;
			printf("%c", str[i]);
			temp = '#';
			num = 0;
		}
		else {
			if (str[i] != temp) {
				temp = str[i];
				num = 1;
			}
			else {
				num++;
				if (num == k) {
					printf("%c", temp);
					num = 0;
				}
			}
		}
		
	}
	return 0;
}