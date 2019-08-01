#include<cstdio>
#include<vector>
using namespace std;

#define maxn 100

int main() {
	int N;
	char str[maxn];
	vector<int> v;
	bool fu ,notlegal,isfloat;
	int n1, n2,si,flnum;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		si = 0,n1 = 0, n2 = 0,flnum=0;
		notlegal = false,isfloat = false;
		if (str[0] == '-') {
			fu = true;
			si++;
		}
		else
			fu = false;
		for (; si < maxn; si++) {
			if (str[si] == '\0')
				break;
			else if((str[si]>='0' && str[si] <= '9') || str[si]=='.'){
				if (isfloat == false) {
					if (str[si] == '.') {
						isfloat = true;
					}
					else {
						n1 = n1 * 10 + str[si] - '0';

					}
				}
				else {
					if (str[si] == '.') {
						notlegal = true;
						break;
					}
					else {
					    n2 = n2*10+ str[si] - '0';
						flnum++;
					}
				}

			}
			else {
				notlegal = true;
				break;
			}
		}
		//判断值的时候要将整数部分和小数部分一起算
		if (n1 > 1000 || flnum > 2)
			notlegal = true;
		if(n1*100+n2>100000)
			notlegal = true;
		if (notlegal) {
			printf("ERROR: %s is not a legal number\n", str);
		}
		else {
			if (flnum == 1)
				n2 *= 10;
			int nnn = n1 * 100 + n2;
			if (fu)
				nnn *= -1;
			v.push_back(nnn);
		}
	}
	if (v.size() == 0) {
		printf("The average of 0 numbers is Undefined\n");
	}
	else if (v.size()==1) {
		double sum = 1.0*v[0]/100;
		printf("The average of 1 number is %.2f", sum);
	}
	else {
		double sum = 0;
		for (int ii = 0; ii < v.size(); ii++) {
			sum += (1.0*v[ii]);
		}
		sum /= v.size();
		sum /= 100;
		if (sum<0 && sum>-0.005)
			sum = 0;
		printf("The average of %d numbers is %.2f",v.size(), sum);
	}
	return 0;
}