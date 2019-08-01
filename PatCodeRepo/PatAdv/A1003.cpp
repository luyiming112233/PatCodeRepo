#include<cstdio>

struct answer {
	int min_dis;
	int num;
	int max_hand;
};

int main() {
	int N, M, C1, C2,ti,tj,td;
	bool city[500];
	for (int i = 0; i < 500; i++)
		city[i] = false;
	scanf("%d%d%d%d", &N, &M, &C1, &C2);
	int *dis = new int[N],*hand=new int[N],**mat = new int*[N],**hmat = new int*[N];
	//��ʼ������
	for (int i = 0; i < N; i++)
		dis[i] = 0x3ffffff;
    //������е�������
	for (int i = 0; i < N; i++)
		scanf("%d", &hand[i]);
	//��ʼ������֮���·����
	for (int i = 0; i < N; i++) {
		mat[i] = new int[N];
		hmat[i] = new int[N];
		for (int j = 0; j < N; j++) {
			mat[i][j] = -1;
			hmat[i][j] = 0;
		}
	}
	//�������֮���·����
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &ti, &tj, &td);
		mat[ti][tj] = td;
		hmat[ti][tj] = hand[tj];
	}
	//��ʼ����������
	for (int i = 0; i < N; i++)
		hmat[i][i] = hand[i];
	//��ʼ����
	struct answer an;
	an.max_hand = 0;
	an.min_dis = 0x3ffffff;
	an.num = 0;
	//��ʼ���������
	city[C1] = false;
	dis[C1] = 0;
	//��ʼ����
	int min_dis,cid;
	for (int i = 0; i < N; i++) {
	    //Ѱ��δ�ﵽ�����·��
		min_dis = 0x3fffffff;
		for (int j = 0; j < N; j++) {
			if (min_dis > dis[j] &&city[j]==false) {
				min_dis = dis[j];
				cid = j;
			}
		}
		//��ǵ�ǰ�����Ѿ�����
		city[cid] = true;
		//�������·��
		for (int j = 0; j < N; j++) {
			if (mat[cid][j] != -1) {
				//�µ�·��
				if (dis[j] > mat[cid][j] + dis[cid]) {
					dis[j] = mat[cid][j] + dis[cid];
					//�����������
					hmat[cid][j] = hmat[cid][j] + hand[cid];
					//���Ŀ�ĵ����յ�
					if (j == C2) {
						if (dis[j] < an.min_dis) {
							an.num = 1;
							an.min_dis = dis[j];
							an.max_hand = hmat[cid][j];
						}
					}
				}
				//���Ȳ���
				else if (dis[j] == mat[cid][j] + dis[cid]) {
					//dis[j] = mat[cid][j] + dis[cid];
					//�����������
					if (hmat[cid][j] < hmat[cid][j] + hand[cid])
						hmat[cid][j] = hmat[cid][j] + hand[cid];
					//���Ŀ�ĵ����յ㣬����·������������
					if (j == C2) {
						if (dis[j] == an.min_dis) {
							an.num++;
							if (hmat[cid][j] > an.max_hand)
								an.max_hand = hmat[cid][j];
						}
					}
				}
			}
		}
		
	}
	printf("%d %d\n", an.num, an.max_hand);
}