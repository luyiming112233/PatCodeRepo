#include<iostream>
#include<string>
using namespace std;

int main() {
	int n, m, count = 0;
	while (cin >> m >> n) {
		if (m == 0 || n == 0)
			continue;
		if (count == 0) {
			cout << n * m << " " << n - 1;
		}
		else {
			cout << " " << n * m << " " << n - 1;
		}
		count++;
	}

	if (count == 0)
		cout << "0 0";
	cout << endl;
	return 0;
}