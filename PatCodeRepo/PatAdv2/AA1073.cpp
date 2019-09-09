#include<cstdio>
#include<vector>
using namespace std;

#define maxn 10010

int main() {
	char str[maxn];
	int i = 1,wei=0;
	bool left=false;
	scanf("%s", str);
	if (str[0] == '-') printf("-");
	vector<int> v;
	for (i = 1; i < maxn; i++) {
		if (str[i] == '.')
			continue;
		if (str[i] == 'E')
			break;
		v.push_back(str[i] - '0');
	}
	i++;
	if (str[i] == '-') {
		left = true;
	}
	i++;
	for (; i < maxn; i++) {
		if (str[i] == '\0')
			break;
		wei = wei * 10 + str[i] - '0';
	}
	if (left) {
		printf("0.");
		for (int i = 1; i < wei; i++)
			printf("0");
		for (int i = 0; i < v.size(); i++)
			printf("%d", v[i]);
	}
	else {
		if (wei > v.size() - 2) {
			for (int i = 0; i < v.size(); i++)
				printf("%d", v[i]);
			for (int i = 0; i < wei + 1 - v.size();i++)
				printf("0");
		}
		else {
			int num = 0;
			for (int i = 0; i <= wei; i++) 
				num = num * 10 + v[i];
			printf("%d.", num);
			for (int i = wei + 1; i < v.size(); i++)
				printf("%d", v[i]);
		}
	}
	return 0;
}