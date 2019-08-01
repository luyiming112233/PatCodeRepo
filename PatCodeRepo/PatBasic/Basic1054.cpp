#include<cstdio>

#define size 100

int main() {
	int n,legal_n=0,j,point,fwei;
	char str[size];
	double sum = 0, num,numf;
	bool fu,flag;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		num = 0;//整数部分
		numf = 0;//小数部分
		fwei = 10;
		j = 0;
		point = 0;
		fu = false;
		flag = true;
		if (str[0] == '-') {
			fu = true;
			j++;
		}
		while (str[j] != '\0'  && flag) {
			if (str[j] - '0' >= 0 && str[j] - '0' < 10) {
				if (point == 0) {
					//if (j>0 && str[j-1]=='0' &&num<0.1)
					//	flag = false;
					num = num * 10 + str[j] - '0';
				}
				else if (point == 1) {
					numf += (1.0)*(str[j] - '0') / fwei;
					fwei *= 10;
				}
			}
			else if (str[j] == '.') {
				point++;
				if (point > 1) 
					flag = false;
			}
			else
				flag = false;
			j++;
		}
		if (num + numf > 1000  || fwei>1000)
			flag = false;


		if (flag) {
			num += numf;
			if (fu)
				num = -num;
			sum += num;
			legal_n++;
			//printf("%lf\n", num);
		}
		else {
			printf("ERROR: %s is not a legal number\n",str);
		}
	}
	
	if (legal_n == 0)
		printf("The average of 0 numbers is Undefined\n");
	else if (legal_n == 1) {
		sum /= legal_n;
		if (sum<0 && sum>-0.005)
			sum = -sum;
		printf("The average of 1 number is %.2lf\n", sum);
	}
	else {
		sum /= legal_n;
		if (sum<0 && sum>-0.005)
			sum = -sum;
		printf("The average of %d numbers is %.2lf\n", legal_n,sum);
	}
	return 0;
}