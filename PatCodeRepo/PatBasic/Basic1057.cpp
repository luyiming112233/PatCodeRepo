#include<cstdio>
#include<iostream>
using namespace std;

#define size 100010

int main() {
	char str[size];
	int sv, bv, sum = 0, num[2] = {0};
	cin.getline(str, size);
	for (int i = 0; i < size; i++) {
		if (str[i] == '\0')
			break;
		sv = str[i] - 'a' + 1;
		bv = str[i] - 'A' + 1;
		if (sv > 0 && sv <= 26)
			sum += sv;
		else if (bv > 0 && bv <= 26)
			sum += bv;
	}
	//�����Ϊ0����ôҪ�ֶ���num_0+1
	//if (sum == 0)
	//	num[0]++;
	while (sum != 0) {
		num[sum % 2]++;
		sum /= 2;
	}
	printf("%d %d\n", num[0], num[1]);
	return 0;
}