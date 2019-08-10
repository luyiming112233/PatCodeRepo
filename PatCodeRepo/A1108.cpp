#include<cstdio>
#include<vector>
using namespace std;

#define slen 1000

int main() {
	vector<double> v;
	char str[slen];
	int N;
	bool flag,fu,zheng;
	int point,wei;
	double num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		flag = true;
		zheng = false;
		fu = false;
		point = 0;
		wei = 0;
		num = 0;
		for (int j = 0; j < slen; j++) {
			if (str[j] == '\0')
				break;
			if (j == 0 && str[j] == '-') {
				fu = true;
				continue;
			}
			//ÅÐ¶Ï×Ö·û
			if (str[j] >= '0' && str[j] <= '9') {
				num = 10 * num + str[j] - '0';
				zheng = true;
				if (point == 1)
					wei++;
			}
			else if (str[j] == '.') {
				if (zheng == false)
					flag = false;
				point++;
			}
			else {
				flag = false;
				break;
			}
			//ÅÐ¶ÏÊý×ÖÊÇ·ñ·ûºÏÒªÇó
			if (point > 1 || wei > 2) {
				flag = false;
				break;
			}
		}
		if (point == 1) {
			switch (wei)
			{
			case 0:
				flag = false;
				break;
			case 1:
				num /= 10;
				break;
			case 2:
				num /= 100;
				break;
			}
		}
		if (zheng == false)
			flag = false;
		if (num > 1000.0)
			flag = false;
		if (flag) {
			if (fu)
				num = -num;
			v.push_back(num);
		}
		else {
			printf("ERROR: %s is not a legal number\n", str);
		}
	}
	if (v.size() == 0)
		printf("The average of 0 numbers is Undefined");
	else if(v.size()==1)
		printf("The average of 1 number is %.2f",v[0]);
	else {
		double temp = 0;
		for (int i = 0; i < v.size(); i++) {
			temp += v[i];
		}
		printf("The average of %d numbers is %.2f", v.size(),temp/v.size());
	}
	return 0;
}