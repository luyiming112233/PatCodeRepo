#include<iostream>
#include<string>
using namespace std;

int main() {
	int n, len, i, A_left_num, A_med_num, A_right_num, P_num, T_num;
	bool flag;
	string str;
	cin >> n;
	while (n > 0) {
		n--;
		//��ʼ��
		flag = true;
		A_left_num = 0, A_med_num = 0, A_right_num = 0, P_num = 0, T_num = 0;
		cin >> str;
		len = str.length();
		for (i = 0; i < len&&flag; i++) {
			flag = false;
			//�����ǰ�ַ���P
			if (str[i] == 'P') {
				P_num++;
				flag = true;
			}
			//�����ǰ�ַ���T
			if (str[i] == 'T') {
				T_num++;
				flag = true;
			}
			//�����ǰ�ַ���A
			if (str[i] == 'A') {
				flag = true;
				if (P_num == 0 && T_num == 0)
					A_left_num++;
				if (P_num == 1 && T_num == 0)
					A_med_num++;
				if (P_num == 1 && T_num == 1)
					A_right_num++;
			}
		}

		//���û�������ַ�
		if (flag&&A_med_num*A_left_num == A_right_num && A_med_num > 0 && P_num == 1 && T_num == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}
	return 0;
}
