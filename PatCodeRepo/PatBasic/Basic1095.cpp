#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

struct stu {
	char str[14];
	char L;
	int cid;
	int day;
	int tid;
	int grade;
};

struct cla
{
	int cid;
	int num;
};

bool cmp(stu a, stu b) {
	if (a.grade != b.grade)
		return a.grade > b.grade;
	else
		return (string)a.str < (string)b.str;
}

bool cmpcla(cla a, cla b) {
	if (a.num != b.num)
		return a.num > b.num;
	else
		return a.cid < b.cid;
}

void c1(int id, vector<stu> &v) {
	char L;
	scanf(" %c", &L);
	bool find = false;
	printf("Case %d: 1 %c\n", id, L);
	for (int i = 0; i < v.size(); i++) {
		if (L == v[i].L) {
			find = true;
			printf("%s %d\n", v[i].str, v[i].grade);
		}
	}
	if (find == false)
		printf("NA\n");
}

void c2(int id, vector<stu> &v) {
	int cid,num=0,sum=0;
	scanf("%d", &cid);
	printf("Case %d: 2 %d\n", id, cid);
	for (int i = 0; i < v.size(); i++) {
		if (cid == v[i].cid) {
			num++;
			sum += v[i].grade;
		}
	}
	if(num!=0)
    	printf("%d %d\n", num, sum);
	else
		printf("NA\n");
}

void c3(int id, vector<stu> &v) {
	int day, a[1000] = {0};
	vector<cla> cv;
	cla temp;
	scanf("%d", &day);
	printf("Case %d: 3 %06d\n", id, day);
	for (int i = 0; i < v.size(); i++) {
		if (day == v[i].day) {
			a[v[i].cid]++;
		}
	}
	for (int i = 100; i < 1000; i++) {
		if (a[i] > 0) {
			temp.cid = i;
			temp.num = a[i];
			cv.push_back(temp);
		}
	}
	if (cv.size() != 0) {
		sort(cv.begin(), cv.end(), cmpcla);
		for (int i = 0; i < cv.size(); i++) {
			printf("%d %d\n", cv[i].cid, cv[i].num);
		}
	}
	else
		printf("NA\n");
}

int main() {
	vector<stu> v;
	stu temp;
	int N, M,z;
	char str[14];
	scanf("%d %d", &N,&M);
	for (int i = 0; i < N; i++) {
		scanf("%s %d", str, &temp.grade);
		temp.L = str[0];
		temp.cid = (str[1] - '0') * 100 + (str[2] - '0') * 10 + (str[3] - '0');
		temp.day = (str[4] - '0') * 100000 + (str[5] - '0') * 10000 + (str[6] - '0') * 1000 + (str[7] - '0') * 100 + (str[8] - '0') * 10 + (str[9] - '0');
		temp.tid = (str[10] - '0') * 100 + (str[11] - '0') * 10 + (str[12] - '0');
		strcpy(temp.str, str);
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < M; i++) {
		scanf("%d", &z);
		switch (z) {
		case 1:c1(i + 1, v); break;
		case 2:c2(i + 1, v); break;
		case 3:c3(i + 1, v); break;
		}
	}
	return 0;
}