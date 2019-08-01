#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

#define maxn 60
#define ERROR "error"

string getL(int num,string s) {
	string str;
	int d = 0,start,len;
	bool flag = true;
	for (int i = 0; i < s.length(); i++) {
		if (flag) {
			if (s[i] == '[') {
				flag = false;
				start = i + 1;
				len = 0;
			}
		}
		else {
			if (s[i] == ']') {
				flag = true;
				if(len>0)
    				d++;
			}
			else {
				len++;
			}
		}
		if (d == num) {
			//cout << s.substr(start, len) << endl;
			return s.substr(start, len);
		}
	}
	return ERROR;
}

int main() {
	string shand,seye,smonth;
	int nums[5],K;
	getline(cin, shand);
	getline(cin, seye);
	getline(cin, smonth);
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d%d%d%d%d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4]);
		if (nums[0]<0 || nums[1] < 0 || nums[2] < 0 || nums[3] < 0 || nums[4] < 0) {
			cout << "Are you kidding me? @\\/@\n";
		}
		else if(getL(nums[0],shand)== ERROR || getL(nums[1], seye) == ERROR || getL(nums[2], smonth) == ERROR || getL(nums[3], seye) == ERROR || getL(nums[4], shand) == ERROR)
		{
			cout << "Are you kidding me? @\\/@\n";
		}
		else {
			cout << getL(nums[0], shand)<<"("<< getL(nums[1], seye)<< getL(nums[2], smonth)<< getL(nums[3], seye) <<")"<< getL(nums[4], shand)<<endl;
		}
	}
	return 0;
}
