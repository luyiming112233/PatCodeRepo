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
		//初始化
		flag = true;
		A_left_num = 0, A_med_num = 0, A_right_num = 0, P_num = 0, T_num = 0;
		cin >> str;
		len = str.length();
		for (i = 0; i < len&&flag; i++) {
			flag = false;
			//如果当前字符是P
			if (str[i] == 'P') {
				P_num++;
				flag = true;
			}
			//如果当前字符是T
			if (str[i] == 'T') {
				T_num++;
				flag = true;
			}
			//如果当前字符是A
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

		//如果没有其他字符
		if (flag&&A_med_num*A_left_num == A_right_num && A_med_num > 0 && P_num == 1 && T_num == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}
	return 0;
}
