#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string num;
	cin >> num;

	int len = num.length(), sum = 0, i;
	for (i = 0; i < len; i++) {
		sum += ((int)num[i] - '0');
	}

	vector<int> v;

	while (sum != 0) {
		v.push_back(sum % 10);
		sum /= 10;
	}

	for (i = 0; i < v.size(); i++) {
		if (i != 0) {
			cout << " ";
		}

		switch (v[v.size() - 1 - i]) {
		case 0:cout << "ling"; break;
		case 1:cout << "yi"; break;
		case 2:cout << "er"; break;
		case 3:cout << "san"; break;
		case 4:cout << "si"; break;
		case 5:cout << "wu"; break;
		case 6:cout << "liu"; break;
		case 7:cout << "qi"; break;
		case 8:cout << "ba"; break;
		case 9:cout << "jiu"; break;
		}
	}
	cout << endl;
	return 0;
}