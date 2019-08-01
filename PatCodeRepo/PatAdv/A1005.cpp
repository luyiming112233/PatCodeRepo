#include<cstdio>
#include<vector>
using namespace std;

#define ssize 110

int main() {
	char str[ssize];
	scanf("%s", str);
	int sum = 0;
	vector<int> v;
	for (int i = 0; i < ssize; i++) {
		if (str[i] == '\0')
			break;
		sum += (str[i] - '0');
	}
	if (sum == 0)
		v.push_back(0);
	else {
		while (sum != 0)
		{
			v.push_back(sum % 10);
			sum /= 10;
		}
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		if (i != v.size() - 1)
			printf(" ");
		switch (v[i]) {
		case 0:printf("zero"); break;
		case 1:printf("one"); break;
		case 2:printf("two"); break;
		case 3:printf("three"); break;
		case 4:printf("four"); break;
		case 5:printf("five"); break;
		case 6:printf("six"); break;
		case 7:printf("seven"); break;
		case 8:printf("eight"); break;
		case 9:printf("nine"); break;
		}
	}
	return 0;
}