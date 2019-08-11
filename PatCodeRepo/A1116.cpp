#include<cstdio>
#include<map>

using namespace std;

struct stu {
	int id;
	bool check;
	int award;
	stu() {
		check = false;
	}
};

bool isPrime(int num) {
	if (num == 2)
		return true;
	for (int i = 2; i*i <= num; i++) {
		if (num%i == 0)
			return false;
	}
	return true;
}

int main() {
	int N, K,id;
	stu temp;
	map<int, stu> m;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &temp.id);
		if (i == 1)
			temp.award = 1;
		else if (isPrime(i)) {
			temp.award = 2;
		}
		else {
			temp.award = 3;
		}
		m[temp.id] = temp;
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &id);
		if (m.find(id) == m.end()) {
			printf("%04d: Are you kidding?\n",id);
		}
		else if (m[id].check) {
			printf("%04d: Checked\n", id);
		}
		else{
			m[id].check = true;
			switch (m[id].award) {
			case 1:
				printf("%04d: Mystery Award\n", id);
				break;
			case 2:
				printf("%04d: Minion\n", id);
				break;
			case 3:
				printf("%04d: Chocolate\n", id);
				break;
			}
		}
	}
	return 0;
}