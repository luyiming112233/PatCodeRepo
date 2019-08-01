#include<cstdio>

#define size 10010

int main() {
	//stu中 0：不在排名，1：神秘大奖，2：小黄人，3：巧克力，4：check
	int stu[size] = { 0 }, N, K, id;
	int su[size] = { 0 };
	//打素数表
	su[0] = 1;
	su[1] = 1;
	for (int i = 2; i*i < size; i++) {
		for (int j = 2*i; j < size; j += i)
			su[j] = 1;
	}
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &id);
		if (i == 0) {
			stu[id] = 1;
		}
		else if (su[i+1] == 0) {
			stu[id] = 2;
		}
		else {
			stu[id] = 3;
		}
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &id);
		printf("%04d: ", id);
		switch (stu[id]) {
		case 0:printf("Are you kidding?"); break;
		case 1:printf("Mystery Award"); stu[id] = 4; break;
		case 2:printf("Minion"); stu[id] = 4;  break;
		case 3:printf("Chocolate"); stu[id] = 4; break;
		case 4:printf("Checked"); break;
		}
		printf("\n");
	}
	return 0;
}