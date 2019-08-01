#include<iostream>
using namespace std;

int main() {
	int n, num;
	cin >> n;
	num = 0;
	while (n != 1) {
		num++;
		//如果这个数是偶数
		if (n % 2 == 0) {
			n /= 2;
		}
		//如果这个数是奇数
		else {
			n = (3 * n + 1) / 2;
		}
	}
	//输入最后的结果
	cout << num << endl;
	return 0;
}