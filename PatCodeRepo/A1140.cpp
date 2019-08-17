#include<cstdio>
#include<vector>
#include<stack>
using namespace std;

int main() {
	vector<int> a, b;
	int D, N;
	scanf("%d %d", &D, &N);
	b.push_back(D);
	stack<int> s;
	for (int ni = 1; ni < N; ni++) {
		a = b;
		b.clear();
		int v=a[0], num = 1;
		for (int i = 1; i < a.size(); i++) {
			if (v == a[i]) {
				num++;
			}
			else {
				b.push_back(v);
				while (num > 0) {
					s.push(num % 10);
					num /= 10;
				}
				while (!s.empty()) {
					b.push_back(s.top());
					s.pop();
				}
				v = a[i];
				num = 1;
			}
		}
		b.push_back(v);
		while (num > 0) {
			s.push(num % 10);
			num /= 10;
		}
		while (!s.empty()) {
			b.push_back(s.top());
			s.pop();
		}
	}
	for (int i = 0; i < b.size(); i++)
		printf("%d", b[i]);
	return 0;
}