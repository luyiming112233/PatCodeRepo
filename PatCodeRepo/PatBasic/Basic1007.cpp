#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, num = 0, i, j, *arry, s;
	cin >> n;
	arry = new int[n + 1];
	//计算素数表
	for (i = 0; i <= n; i++) {
		arry[i] = 0;
	}
	arry[0] = 1;
	arry[1] = 1;
	for (i = 2; i*i <= n; i++) {
		for (j = 2 * i; j <= n; j += i) {
			arry[j] = 1;
		}
	}

	//寻找素数对
	s = 2;
	for (i = 3; i <= n; i++) {
		if (arry[i] == 0) {
			if (i - s == 2)
				num++;
			s = i;
		}

	}
	cout << num << endl;
	return 0;
}