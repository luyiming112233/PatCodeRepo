#include<cstdio>
#include<map>
using namespace std;

void display(map<int,int> m) {
	map<int, int>::reverse_iterator mit;
	bool flag = true;
	for (mit = m.rbegin(); mit != m.rend(); mit++) {
		if (mit->second != 0) {
			if (flag) {
				printf("%d %d", mit->second, mit->first);
				flag = false;
			}
			else {
				printf(" %d %d", mit->second, mit->first);
			}
		}
	}
	if (flag) {
		printf("0 0");
	}
	printf("\n");
}

int main() {
	map<int, int> a, b, add, chen;
	map<int, int>::iterator it,it2,it3;
	int N, c1, c2;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &c1, &c2);
		a[c2] = c1;
	}
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &c1, &c2);
		b[c2] = c1;
	}
	//chen
	for (it = a.begin(); it != a.end(); it++) {
		for (it2 = b.begin(); it2 != b.end(); it2++) {
			c1 = it->second*it2->second;
			c2 = it->first + it2->first;
			it3 = chen.find(c2);
			if (it3 == chen.end()) {
				chen[c2] = c1;
			}
			else {
				it3->second += c1;
			}
		}
	}
	display(chen);

	//add
	for (it = a.begin(); it != a.end(); it++) {
		it2 = add.find(it->first);
		if (it2 == add.end()) {
			add[it->first] = it->second;
		}
		else {
			it2->second += it->second;
		}
	}
	for (it = b.begin(); it != b.end(); it++) {
		it2 = add.find(it->first);
		if (it2 == add.end()) {
			add[it->first] = it->second;
		}
		else {
			it2->second += it->second;
		}
	}
	display(add);

	return 0;
}
