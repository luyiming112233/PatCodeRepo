#include<cstdio>
#include<vector>
using namespace std;

int main() {
	char N[25];
	int temp,jin,i,la,lb,va,vb;
	char a[25], b[25];
	vector<int> v,answer;
	scanf("%s", &N);
	scanf("%s", &a);
	scanf("%s", &b);
	for (i = 0; i < 25; i++) {
		if (N[i] == '\0')
			break;
		temp = N[i] - '0';
		if (temp == 0)
			temp = 10;
		v.push_back(temp);
	}
	for (la = 0; la < 25; la++) {
		if (a[la] == '\0')
			break;
	}
	for (lb = 0; lb < 25; lb++) {
		if (b[lb] == '\0')
			break;
	}

	jin = 0;
	i = 1;
	while (la>=i || lb>=i) {
		if (la >= i) {
			va = a[la - i] - '0';
		}
		else {
			va = 0;
		}
		if (lb >= i) {
			vb = b[lb - i] - '0';
		}
		else {
			vb = 0;
		}
		temp = va + vb + jin;
		jin = temp / v[v.size() - i];
		answer.push_back(temp % v[v.size() - i]);
		i++;
	}
	if (jin > 0)
		answer.push_back(jin);
	bool first = true;
	for (i = 0; i < answer.size(); i++) {
		if (answer[answer.size() - 1 - i] == 0 && first) {
			continue;
		}
		printf("%d", answer[answer.size() - 1 - i]);
		first = false;
	}
	if (first)
		printf("0");
	return 0;
}
