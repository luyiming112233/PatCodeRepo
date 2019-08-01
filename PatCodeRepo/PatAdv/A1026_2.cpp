#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxt 110

struct player {
	int arrive;//�ﵽʱ��
	int ptime;//��ʼ��ˣʱ��
	int wtime;//��ˣ��ʱ��
	int tag;
	bool flag;
};

struct table
{
	int time;
	int tag;
	int num;
};

int N, K, M;
struct table tables[maxt];
vector<player> v;

int time2num(int hh, int mm, int ss) {
	return hh * 3600 + mm * 60 + ss;
}

void print_time(int num) {
	int hh = num / 3600;
	int mm = num % 3600 / 60;
	int ss = num % 60;
	printf("%02d:%02d:%02d", hh, mm, ss);
}

bool cmp(player a, player b) {
	return a.arrive < b.arrive;
}

bool cmp2(player a, player b) {
	if(a.ptime!=b.ptime)
    	return a.ptime < b.ptime;
	else
		return a.arrive < b.arrive;
}

//ѡ����ͨ��
int getTable() {
	int t, min = 1000000000;
	for (int i = 1; i <= K; i++) {
		if (tables[i].time < min) {
			min = tables[i].time;
			t = i;
		}
	}
	if (min >= 75600)
		return -1;
	else
		return t;
}

//ѡ��VIP��
int getVipTable() {
	int t, min = 1000000000;
	for (int i = 1; i <= K; i++) {
		if (tables[i].time < min && tables[i].tag==1) {
			min = tables[i].time;
			t = i;
		}
	}
	if (min >= 75600)
		return -1;
	else
		return t;
}

int findVip(int p,int t) {
	for (int i = p; i < v.size(); i++) {
		if (v[i].arrive > tables[t].time)
			break;
		if (v[i].tag == 1 && v[i].flag == false) {
			return i;
		}
	}
	return -1;
}

//����ȴ�ʱ��
int calWait(int a,int p) {
	int diff = (p - a) / 6;
	if (diff % 10 >= 5)
	    diff+=10;
	return diff / 10;
}

//�����û�
void service(int p,int t) {
	//����ʱ����Է���
	if (v[p].arrive >= tables[t].time) {
		v[p].ptime = v[p].arrive;
	}
	else {
		v[p].ptime = tables[t].time;
	}
	tables[t].num++;
	tables[t].time = v[p].ptime + v[p].wtime;
	v[p].flag = true;
}

int main() {
	int hh, mm, ss,ww,tag,arive,vs,ta,vipta,vi;
	player temp;
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &ww, &temp.tag);
		arive = time2num(hh, mm, ss);
		if (ww > 120)
			ww = 120;
		if (arive < 28800 || arive >= 75600)
			continue;
		temp.arrive = arive;
		temp.flag = false;
		temp.wtime = ww * 60;
		v.push_back(temp);
	}
	scanf("%d %d", &K, &M);
	//��ʼ��table
	for (int i = 1; i <= K; i++) {
		tables[i].num = 0;
		tables[i].time = 28800;
		tables[i].tag = 0;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &vs);
		tables[vs].tag = 1;
	}
	sort(v.begin(), v.end(), cmp);
	//��ʼ�ж�
	for (int i = 0; i < v.size(); i++) {
		//��ǰ�ͻ��Ѿ�����������
		if (v[i].flag == true)
			continue;
		ta = getTable();
		//�������Ӷ����ڵ���21��00
		if (ta == -1)
			break;
		//��ǰ�˿���VIP
		if (v[i].tag == 1) {
			//��ѡVIP��
			vipta = getVipTable();
			if (vipta != -1 && tables[vipta].time <= v[i].arrive) {
				ta = vipta;
			}
			service(i, ta);
		}
		//��ǰ�û�����ͨ�û�
		else {
		    //�������ͨ�������Է���
			if (tables[ta].tag == 0) {
				service(i, ta);
			}
			//�����VIP�����ж��Ƿ���VIP�û����
			else {
				vi = findVip(i, ta);
				//û��VIP
				if (vi == -1) {
					service(i, ta);
				}
				//�����������VIP
				else {
					service(vi, ta);
					//�����
					i--;
				}
			}
		}

	}
	sort(v.begin(), v.end(), cmp2);
	for (int i = 0; i < v.size(); i++) {
		if (v[i].flag == true) {
			print_time(v[i].arrive);
			printf(" ");
			print_time(v[i].ptime);
			printf(" ");
			printf("%d\n", calWait(v[i].arrive, v[i].ptime));
		}
	}
	//���table������
	for (int i = 1; i <= K; i++) {
		if (i == 1)
			printf("%d", tables[i].num);
		else {
			printf(" %d", tables[i].num);
		}
	}
	return 0;
}