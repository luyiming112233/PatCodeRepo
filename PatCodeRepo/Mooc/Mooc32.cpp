#include<cstdio>
#include<map>
#include<string>
#include<string.h>
using namespace std;

#define slen 50

bool judgeID(int id) {
	if (id > 1000 && id <= 1e10)
		return true;
	return false;
}

bool judgePass(char *pass) {
	int len;
	for (len = 0; len < slen; len++)
		if (pass[len] == '\0')
			break;
	if (len >= 6 && len <= 16)
		return true;
	return false;
}

int main() {
	int N;
	map<int, string> m;
	map<int, string>::iterator it;
	char op;
	int id;
	char pass[slen];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("\n%c %d %s", &op, &id, pass);
		if (!judgeID(id)) {
			printf("ERROR: Not Exist\n");
			continue;
		}
		else if (!judgePass(pass)) {
			printf("ERROR: Wrong PW\n");
			continue;
		}
		it = m.find(id);
		if (op == 'N') {
			if (it == m.end()) {
				printf("New: OK\n");
				m[id] = pass;
			}
			else {
				printf("ERROR: Exist\n");
			}
		}
		else if (op == 'L') {
			if (it == m.end())
				printf("ERROR: Not Exist\n");
			else {
			    if(m[id]==(string)pass)
					printf("Login: OK\n");
				else
					printf("ERROR: Wrong PW\n");
			}
		}
	}
	return 0;
}