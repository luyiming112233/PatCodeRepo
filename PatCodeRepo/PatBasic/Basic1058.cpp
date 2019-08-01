#include<cstdio>
#include<iostream>
using namespace std;

#define size 1000
#define ssize 100000

struct ques {
	int grade;//分数
	int answer[5];
	int anum;
	int error;
};

int main() {
	int N, M, snum, tnum, stu[size] = {0};
	scanf("%d%d", &N, &M);
	ques *q = new ques[M];
	char ch,str[ssize];
	for (int i = 0; i < M; i++) {
		//读取题目分值
		scanf("%d", &q[i].grade);
		//错数设为0
		q[i].error = 0;
		scanf("%d%d", &snum, &tnum);
		q[i].anum = tnum;
		for (int j = 0; j < snum; j++) {
			q[i].answer[i] = 0;
		}
		for (int j = 0; j < tnum; j++) {
			scanf(" %c", &ch);
			q[i].answer[ch - 'a'] = 1;
		}
		getchar();
	}
	//读入学生数据
	int anum;
	bool flag;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			flag = true;
			scanf("(%d", &anum);
			//读取学生的答案
			for (int k = 0; k < anum; k++) {
				scanf(" %c", &ch);
				if (q[j].answer[ch - 'a'] != 1)
					flag = false;
			}
			if (anum != q[j].anum)
				flag = false;
			scanf(")");
			if (flag)
				stu[i] += q[j].grade;
			else
				q[j].error++;
			getchar();
		}
		
	}
	for (int i = 0; i < N; i++)
		printf("%d\n", stu[i]);
	int max_error = 0;
	for (int i = 0; i < M; i++) {
		if (q[i].error > max_error) {
			max_error = q[i].error;
		}
	}
	if (max_error == 0) {
		printf("Too simple\n");
	}
	else {
		printf("%d",max_error);
		for (int i = 0; i < M; i++) {
			if (max_error == q[i].error) {
				printf(" %d", i + 1);
			}
		}
	}
	return 0;
}