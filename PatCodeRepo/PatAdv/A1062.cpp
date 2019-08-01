#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct man {
	int id;//8λ��0
	int talent;
	int virtue;
	int type;
};

//�ж��Ƿ񼰸��Լ��Ƿ��д�������
bool judge(man m,int L) {
	if (m.talent < L || m.talent>100)
		return false;
	if (m.virtue < L || m.virtue>100)
		return false;
	return true;
}

bool cmp(man a, man b) {
	if (a.type != b.type) {
		return a.type < b.type;
	}else if (a.talent + a.virtue != b.talent + b.virtue) {
		return a.talent + a.virtue > b.talent + b.virtue;
	}
	else if (a.virtue != b.virtue) {
		return a.virtue > b.virtue;
	}
	else
		return a.id < b.id;
}

int getType(man m,int H) {
	if (m.talent >= H && m.virtue >= H)
		return 1;
	if (m.virtue >= H)
		return 2;
	if (m.virtue >= m.talent)
		return 3;
	else
		return 4;
}

int main() {
	int N, L, H;
	vector<man> v;
	man temp;
	scanf("%d %d %d", &N, &L, &H);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &temp.id, &temp.virtue, &temp.talent);
		if (!judge(temp,L))
			continue;
		temp.type = getType(temp, H);
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), cmp);
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%08d %d %d\n", v[i].id, v[i].virtue, v[i].talent);
	}
	return 0;
}