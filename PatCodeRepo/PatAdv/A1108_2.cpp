#include<cstdio>
#include<vector>
using namespace std;

#define slen 100

int main() {
	vector<double> v;
	int N;
	char str[slen],temp[slen];
	double num;
	bool flag;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		sscanf(str, "%lf", &num);
		flag = true;
		sprintf(temp, "%.2lf", num);
		for (int j = 0; j < slen; j++) {
			if (str[j] == '\0')
				break;
		    if(temp[j]!=str[j]){
				flag = false;
				break;
			}
		}
		if (num > 1000 || num < -1000)
			flag = false;
		if (flag) {
			v.push_back(num);
		}
		else {
			printf("ERROR: %s is not a legal number\n", str);
		}
	}
	if (v.size() == 0)
		printf("The average of 0 numbers is Undefined");
	else if (v.size() == 1)
		printf("The average of 1 number is %.2f", v[0]);
	else {
		double temp = 0;
		for (int i = 0; i < v.size(); i++) {
			temp += v[i];
		}
		printf("The average of %d numbers is %.2f", v.size(), temp / v.size());
	}
	return 0;
}