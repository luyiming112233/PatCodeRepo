#include<cstdio>
#include<vector>
using namespace std;

#define maxn 10010

int main() {
	char str[maxn];
	vector<char> v;
	int i = 1,bit,wei=0;
	scanf("%s", str);
	bool flag,right;
	if (str[0] == '+')
		flag = true;
	if (str[0] == '-')
		flag = false;
	for (i = 1; i < maxn; i++) {
		if (str[i] == 'E')
			break;
		if (str[i] >= '0' && str[i] <= '9') {
			v.push_back(str[i]);
		}
		if (str[i] == '.')
			bit = v.size();
	}
	i++;
	if (str[i] == '+')
		right = true;
	else
		right = false;
	//开始读位数
	i++;
	for (; i < maxn; i++) {
		if (str[i] == '\0')
			break;
		else {
			wei = wei * 10 + str[i] - '0';
		}
	}
	if (right) {
		bit += wei;
	}
	else {
		bit -= wei;
	}
	if (!flag)
		printf("-");
	if (bit <= 0) {
		bool first = true;
		for (int i = bit; i <= 0; i++) {
			printf("0");
			if (first) {
				printf(".");
				first = false;
			}
		}
		for (int i = 0; i < v.size(); i++) {
			printf("%c", v[i]);
		}
	}
	else if (bit >= v.size()) {
		bool noZero = true;
		for (int i = 0; i < v.size(); i++) {
			if (noZero) {
				if (v[i] == '0')
					continue;
				else {
					noZero = false;
				}
			}
			printf("%c", v[i]);
		}
		for (int i = v.size(); i < bit; i++)
			printf("0");
	}
	else {
		bool noZero = true;
		for (int i = 0; i < v.size(); i++) {
			if (noZero) {
				if (v[i] == '0' && i<bit) 
					continue;
				else {
					noZero = false;
				}
			}
			printf("%c", v[i]);
			if (i == bit-1)
				printf(".");
		}
	}
	return 0;
}