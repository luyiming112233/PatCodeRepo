#include<cstdio>
#include<string.h>

#define maxn 12
#define high 1000
#define low -1

struct stu {
	char name[maxn];
	char gender;
	char ID[maxn];
	int grade;
};

int main() {
	int N;
	bool NA = false;
	stu temp, lmale, hfemale;
	lmale.grade = high;
	hfemale.grade = low;
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s ", temp.name);
		scanf("%c", &temp.gender);
		scanf("%s", temp.ID);
		scanf("%d", &temp.grade);
		if (temp.grade < 0 || temp.grade>100) {
			continue;
		}
		if (temp.gender == 'M') {
			if (temp.grade < lmale.grade) {
				lmale.grade = temp.grade;
				strcpy(lmale.name, temp.name);
				strcpy(lmale.ID, temp.ID);
				lmale.grade = temp.grade;
			}
		}
		else if (temp.gender == 'F') {
			if (temp.grade > hfemale.grade) {
				hfemale.grade = temp.grade;
				strcpy(hfemale.name, temp.name);
				strcpy(hfemale.ID, temp.ID);
				hfemale.grade = temp.grade;
			}
		}
	}
	if (hfemale.grade == low) {
		printf("Absent\n");
		NA = true;
	}
	else {
		printf("%s %s\n", hfemale.name, hfemale.ID);
	}
	if (lmale.grade == high) {
		printf("Absent\n");
		NA = true;
	}
	else {
		printf("%s %s\n", lmale.name, lmale.ID);
	}
	if (NA) {
		printf("NA");
	}
	else {
		printf("%d", hfemale.grade - lmale.grade);
	}
	return 0;
}