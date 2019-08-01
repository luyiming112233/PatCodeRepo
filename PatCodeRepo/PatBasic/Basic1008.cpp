#include<iostream>
using namespace std;

int main() {
	int n, m, *arry, i, s, temp, k, tt;
	cin >> n >> m;

	arry = new int[n];
	for (i = 0; i < n; i++)
		cin >> arry[i];


	s = 0;
	k = 0;
	temp = arry[s];
	for (i = 0; i < n; i++) {
		tt = arry[(s + m) % n];
		arry[(s + m) % n] = temp;
		temp = tt;
		s = s + m;
		if (s%n == k) {
			s++;
			k++;
			temp = arry[s%n];
		}
	}

	arry[s%n] = temp;

	for (i = 0; i < n; i++) {
		if (i != 0)
			cout << " ";
		cout << arry[i];
	}
	cout << endl;
	return 0;
}