#include<iostream>
using namespace std;

int main() {
	int n, num;
	cin >> n;
	num = 0;
	while (n != 1) {
		num++;
		//����������ż��
		if (n % 2 == 0) {
			n /= 2;
		}
		//��������������
		else {
			n = (3 * n + 1) / 2;
		}
	}
	//�������Ľ��
	cout << num << endl;
	return 0;
}