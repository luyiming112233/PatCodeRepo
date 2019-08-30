#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define slen 15
#define LL long long

vector<LL> answer;

int getValue(char c) {
	if (c >= '0' && c <= '9') return c - '0';
	else return c - 'a' + 10;
}

LL minR(char *str) {
	LL TR = 0;
	for (int i = 0; i < slen; i++) {
		if (str[i] == '\0') break;
		if (TR < getValue(str[i]))
			TR = getValue(str[i]);
	}
	return TR + 1;
}

LL trans(char *str, LL radix) {
	LL num = 0;
	for (int i = 0; i < slen; i++) {
		if (str[i] == '\0') break;
		num = num * radix + getValue(str[i]);
		if (num < 0) return -1;
	}
	return num;
}

LL cal(char *str, char *n, int radix) {
	LL num = trans(n, radix);
	if (num == -1) return -1;
	LL left = minR(str), right = num + 1, mid;
	if (radix > right) right = radix + 1;
	while (left <= right) {
		mid = (left + right) / 2;
		LL temp = trans(str, mid);
		if (temp == num) {
			answer.push_back(mid);
			right = mid - 1;
		}
		else if (temp<0 || temp>num) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}

int main() {
	char s1[slen], s2[slen];
	int tag, radix;
	scanf("%s %s %d %d", s1, s2, &tag, &radix);
	if (tag == 1) cal(s2, s1, radix);
	else cal(s1, s2, radix);
	if (answer.size() == 0) printf("Impossible");
	else {
		sort(answer.begin(), answer.end());
		printf("%lld", answer[0]);
	}
	return 0;
}
