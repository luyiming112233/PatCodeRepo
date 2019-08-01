#include<cstdio>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;

#define smax 10

struct stu {
	int id;//注意输出格式
	char name[smax];
	int grade;
};

bool judge(stu s) {
	//6位数
	if (s.id > 999999 || s.id < 0)
		return false;
	if (s.grade < 0 || s.grade>100)
		return false;
	int len;
	for (len = 0; len < smax; len++) {
		if (s.name[len] == '\0')
			break;
	}
	if (len > 8)
		return false;
	return true;
}

bool cmp1(stu a,stu b) {
	return a.id < b.id;
}

bool cmp2(stu a, stu b) {
	if (strcmp(a.name, b.name) != 0) {
		return (string)a.name < (string)b.name;
	}
	return a.id < b.id;
}

bool cmp3(stu a, stu b) {
	if (a.grade!=b.grade) {
		return a.grade < b.grade;
	}
	return a.id < b.id;
}

int main() {
	int N, C;
	scanf("%d%d", &N, &C);
	vector<stu> v;
	stu temp;
	for (int i = 0; i < N; i++) {
		scanf("%d %s %d", &temp.id, &temp.name, &temp.grade);
		if (judge(temp))
			v.push_back(temp);
	}
	switch(C) {
	case 1:sort(v.begin(),v.end(),cmp1); break;
	case 2:sort(v.begin(), v.end(), cmp2); break;
	case 3:sort(v.begin(), v.end(), cmp3); break;
	}
	for (int i =0 ; i < v.size(); i++) {
		printf("%06d %s %d\n",v[i].id,v[i].name,v[i].grade);
	}
	return 0;

}