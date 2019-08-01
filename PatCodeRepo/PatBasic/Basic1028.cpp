#include<cstdio>
#include<cstring>

const int tyy = 2014, tmm = 9, tdd = 6;
int month[13][2] = { {0,0},{31,31},{28,29},{31,31},{30,30}
						 ,{31,31},{30,30},{31,31},{31,31}
						 ,{30,30},{31,31},{30,30},{31,31} };

struct people {
	char name[6];
	int yy;
	int mm;
	int dd;
};

bool run(int yy) {
	if ((yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0)
		return true;
	return false;
}

bool islegal(people p) {
	//�ж�����Ƿ���ȷ
	if (p.yy > tyy || p.yy < tyy - 200)
		return false;
	//�ж��·��Ƿ���ȷ
	if (p.mm < 1 || p.mm>12)
		return false;
	//�ж������Ƿ���ȷ
	if (p.dd<1 || p.dd>month[p.mm][run(p.yy)])
		return false;
	//�жϽ�������Ƿ񳬹�
	if (p.yy == tyy && p.mm > tmm)
		return false;
	if (p.yy == tyy && p.mm == tmm && p.dd > tdd)
		return false;
	//�ж�200������Ƿ���ǰ
	if (p.yy == tyy - 200 && p.mm < tmm)
		return false;
	if (p.yy == tyy - 200 && p.mm == tmm && p.dd < tdd)
		return false;
	return true;
}

void copy(people &p, people &c) {
	strcpy(p.name, c.name);
	p.yy = c.yy;
	p.mm = c.mm;
	p.dd = c.dd;
}

//a>bΪtrue
bool islong(people a, people b) {
	if (a.yy > b.yy)
		return true;
	if (a.yy == b.yy && a.mm > b.mm)
		return true;
	if (a.yy == b.yy && a.mm == b.mm && a.dd > b.dd)
		return true;
	return false;
}

int main() {
	int n, num = 0;
	//lpeo��ʾʱ���ֵ��󣬼������С
	//speo��ʾʱ���ֵ��С����������
	struct people temp, lpeo, speo;
	scanf("%d", &n);

	while (n--) {
		scanf("%s %d/%d/%d", temp.name, &temp.yy, &temp.mm, &temp.dd);
		if (islegal(temp)) {
			num++;
			if (num == 1) {
				copy(lpeo, temp);
				copy(speo, temp);
			}
			else {
				if (islong(temp, lpeo)) {
					copy(lpeo, temp);
				}
				if (islong(speo, temp)) {
					copy(speo, temp);
				}
			}
		}//else
		//	printf("%s %d/%d/%d\n",temp.name,temp.yy,temp.mm,temp.dd);
	}
	if (num != 0)
		printf("%d %s %s\n", num, speo.name, lpeo.name);
	else
		printf("%d\n", num);
	return 0;
}