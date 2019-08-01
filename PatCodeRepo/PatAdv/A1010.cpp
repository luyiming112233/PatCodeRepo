#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define csize 11

int trans(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	if (c >= 'a' && c <= 'z') {
		return c - 'a' + 10;
	}
	return 0;
}

int str2num(char str[],int radix) {
	int sum = 0;
	if (radix == 0) {
		for (int i = 0; i < csize; i++) {
			if (str[i] == '\0')
				break;
			sum = sum + trans(str[i]);
		}
	}
	else {
		for (int i = 0; i < csize; i++) {
			if (str[i] == '\0')
				break;
			if (trans(str[i] >= radix))
				return -1;
			sum = sum * radix + trans(str[i]);
		}
	}
	return sum;
}

int main() {
	char num1[csize], num2[csize],a[csize],b[csize];
	int tag, radix,v_a,v_b,radix_b,len_b=0;
	vector<int> v1, v2;
	scanf("%s %s %d %d", num1, num2, &tag, &radix);
	if (tag == 1) {
		strcpy(a, num1);
		strcpy(b, num2);
	}
	else {
		strcpy(a, num2);
		strcpy(b, num1);
	}
	while (b[len_b] != '\0') {
		len_b++;
	}
	//计算a的实际值
	v_a = str2num(a, radix);
	if (trans(b[len_b-1])==str2num(b,0) || str2num(b, 0)==0) {
		v_b = trans(len_b);
		radix_b = trans(len_b) + 1;
	}
	else {
		//可能需要修改，目前起点是2进制
		v_b = str2num(b, 1);
			radix_b = 1;
			while (v_a > v_b) {
				radix_b++;
				v_b = str2num(b, radix_b);
		}
	}
	if (v_b == v_a) {
		printf("%d", radix_b);
	}
	else
		printf("Impossible");
	return 0;
}