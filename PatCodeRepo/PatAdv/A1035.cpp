#include<cstdio>
#include<vector>
using namespace std;

#define maxn 12

struct account {
	char username[maxn], password[maxn];
};

bool judge(char str[]) {
	bool change = false;
	for (int i = 0; i < maxn; i++) {
		if (str[i] == '\0')
			break;
		switch (str[i]) {
		case '1':str[i] = '@'; change = true; break;
		case '0':str[i] = '%'; change = true; break;
		case 'l':str[i] = 'L'; change = true; break;
		case 'O':str[i] = 'o'; change = true; break;
		}
	}
	return change;
}

int main() {
	int N;
	vector<account> v,answer;
	account temp;
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", temp.username);
		scanf("%s", temp.password);
		v.push_back(temp);
	}
	for (int i = 0; i < v.size(); i++) {
		if (judge(v[i].password)) {
			answer.push_back(v[i]);
		}
	}
	if (answer.size() == 0) {
		if (v.size() == 1) {
			printf("There is 1 account and no account is modified");
		}
		else {
			printf("There are %d accounts and no account is modified", v.size());
		}
	}
	else {
		printf("%d\n", answer.size());
		for (int i = 0; i < answer.size(); i++) {
			printf("%s %s\n", answer[i].username, answer[i].password);
		}
	}
	return 0;
}