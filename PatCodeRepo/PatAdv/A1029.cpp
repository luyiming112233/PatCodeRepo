#include<cstdio>
#include<queue>
using namespace std;

int main() {
	queue<int> a, b;
	int Na, Nb, num, L;
	scanf("%d", &Na);
	for (int i = 0; i < Na; i++) {
		scanf("%d", &num);
		a.push(num);
	}
	scanf("%d", &Nb);
	L = (Na + Nb) / 2;
	for (int i = L; i < Na - 1; i++)
		a.pop();
	for (int i = 0; i < Nb; i++) {
		scanf("%d", &num);
		b.push(num);
		if (Na + i > L) {
			if (a.empty()) b.pop();
			else {
				if (a.front() < b.front()) a.pop();
				else b.pop();
			}
		}
	}
	if (a.empty()) printf("%d", b.front());
	else if (b.empty()) printf("%d", a.front());
	else if (a.front() < b.front()) printf("%d", a.front());
	else printf("%d", b.front());
	return 0;
}
