#include<iostream>
#include<vector>
using namespace std;

int main() {
	int num, len = 0, i, j;
	cin >> num;
	vector<int> v;

	while (num != 0) {
		len++;
		v.push_back(num % 10);
		num /= 10;
	}

	for (i = 0; i < len; i++) {
		//��λ
		if (len - i == 3) {
			for (j = 0; j < v[len - 1 - i]; j++)
				cout << "B";
		}
		//ʮλ
		if (len - i == 2) {
			for (j = 0; j < v[len - 1 - i]; j++)
				cout << "S";
		}
		//��λ
		if (len - i == 1) {
			for (j = 0; j < v[len - 1 - i]; j++)
				cout << j + 1;
		}
	}
	cout << endl;
	return 0;
}
