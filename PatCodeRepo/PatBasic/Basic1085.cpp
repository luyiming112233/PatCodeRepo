#include<cstdio>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;

#define usize 100000

struct unv {
	char name[7];
	int B;
	int A;
	int T;
	int snum;
	int sum;
};

//字符串小写
void lower(char a[]) {
	for (int i = 0; i < 7; i++) {
		if (a[i] >= 'A' && a[i] <= 'Z')
			a[i] += 32;
	}
}

bool cmp(unv a, unv b) {
	if (a.sum != b.sum)
		return a.sum > b.sum;
	else if (a.snum != b.snum)
		return a.snum < b.snum;
	else
		return (string)a.name < (string)b.name;
}

int main() {
	int N,num=0,grade,id;
	char str[7], sname[7];
	struct unv *us = new struct unv[usize];
	map<string, int> m;
	map<string, int>::iterator it;
	//初始化
	for (int i = 0; i < usize; i++) {
		us[i].B = 0;
		us[i].A = 0;
		us[i].T = 0;
		us[i].snum = 0;
	}
	
	scanf("%d", &N);
	while (N--) {
		scanf("%s %d %s", str, &grade, sname);
		if (grade < 0 || grade>100)
			continue;
		lower(sname);
		it = m.find(sname);
		//如果没有找到这个学校，在map注册，并输入学校名称
		if (it == m.end()) {
			id = num;
			m[sname] = id;
			num++;
			strcpy(us[id].name, sname);
		}
		else {
			id = it->second;
		}
		switch (str[0]) {
		case 'B':us[id].B += grade; break;
		case 'A':us[id].A += grade; break;
		case 'T':us[id].T += grade; break;
		}
		us[id].snum++;
	}
	for (int i = 0; i < num; i++) {
		double ttt = 1.0*us[i].B / 1.5+ 1.0 * us[i].A + 1.5*us[i].T;
		us[i].sum = ttt;
	}
	sort(us, us + num,cmp);
	printf("%d\n", num);
	int rank = 1,g=-1;
	for (int i = 0; i < num; i++) {
		if (us[i].sum == g) {
			printf("%d %s %d %d\n", rank, us[i].name, us[i].sum, us[i].snum);
		}
		else {
			g = us[i].sum;
			rank = i + 1;
			printf("%d %s %d %d\n", rank, us[i].name, us[i].sum, us[i].snum);
		}
	}
	return 0;
}