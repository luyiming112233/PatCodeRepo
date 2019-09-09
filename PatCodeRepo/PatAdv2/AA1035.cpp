#include<cstdio>
#include<vector>
using namespace std;

#define maxn 15

struct p {
	char account[maxn], pass[maxn];
};

bool judge(char *pass) {
	bool flag = false;
	for (int i = 0; i < maxn; i++) {
		if (pass[i] == '\0') break;
		switch (pass[i]){
		case '1':pass[i] = '@'; flag = true; break;
		case '0':pass[i] = '%'; flag = true; break;
		case 'l':pass[i] = 'L'; flag = true; break;
		case 'O':pass[i] = 'o'; flag = true; break;
		}
	}
	return flag;
}

int main() {
	int N;
	vector<p> v;
	p temp;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("\n%s %s", temp.account,temp.pass);
		if (judge(temp.pass)) v.push_back(temp);
	}
	if (v.size() == 0) {
		if (N == 1) printf("There is 1 account and no account is modified");
		else printf("There are %d accounts and no account is modified", N);
	}
	else {
		printf("%d\n", v.size());
		for (int i = 0; i < v.size(); i++)
			printf("%s %s\n", v[i].account, v[i].pass);
	}
	return 0;
}