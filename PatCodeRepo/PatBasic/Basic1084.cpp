#include<cstdio>
#include<vector>
using namespace std;

int main() {
	char ch,t;
	int N,num;
	vector<char> v,tv,tnum;
	scanf("%c %d", &ch, &N);
	v.push_back(ch);
	N--;
	while (N--) {
		t = v[0];
		num = 1;
		for (int i = 1; i < v.size(); i++) {
			if (v[i] == t)
				num++;
			else {
				tv.push_back(t);
				//将num转化为字符形式
				while (num > 0) {
					tnum.push_back(num % 10 + '0');
					num /= 10;
				}
				for (int tn = tnum.size() - 1; tn >= 0; tn--) {
					tv.push_back(tnum[tn]);
				}
				num = 1;
				t = v[i];
				tnum.clear();
			}
		}
		//将最后一组存入tv
		tv.push_back(t);
		//将num转化为字符形式
		while (num > 0) {
			tnum.push_back(num % 10 + '0');
			num /= 10;
		}
		for (int tn = tnum.size() - 1; tn >= 0; tn--) {
			tv.push_back(tnum[tn] );
		}
		tnum.clear();
		v.assign(tv.begin(),tv.end());
		tv.clear();
	}
	for (int i = 0; i < v.size(); i++)
		printf("%c", v[i]);
	printf("\n");
	return 0;
}