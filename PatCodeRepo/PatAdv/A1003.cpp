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
	//初始化距离
	for (int i = 0; i < N; i++)
		dis[i] = 0x3ffffff;
    //读入城市的人手数
	for (int i = 0; i < N; i++)
		scanf("%d", &hand[i]);
	//初始化城市之间道路矩阵
	for (int i = 0; i < N; i++) {
		mat[i] = new int[N];
		hmat[i] = new int[N];
		for (int j = 0; j < N; j++) {
			mat[i][j] = -1;
			hmat[i][j] = 0;
		}
	}
	//读入城市之间道路矩阵
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &ti, &tj, &td);
		mat[ti][tj] = td;
		hmat[ti][tj] = hand[tj];
	}
	//初始化城市人数
	for (int i = 0; i < N; i++)
		hmat[i][i] = hand[i];
	//初始化答案
	struct answer an;
	an.max_hand = 0;
	an.min_dis = 0x3ffffff;
	an.num = 0;
	//初始化到达城市
	city[C1] = false;
	dis[C1] = 0;
	//开始运算
	int min_dis,cid;
	for (int i = 0; i < N; i++) {
	    //寻找未达到最近的路线
		min_dis = 0x3fffffff;
		for (int j = 0; j < N; j++) {
			if (min_dis > dis[j] &&city[j]==false) {
				min_dis = dis[j];
				cid = j;
			}
		}
		//标记当前城市已经访问
		city[cid] = true;
		//更新最短路径
		for (int j = 0; j < N; j++) {
			if (mat[cid][j] != -1) {
				//新的路线
				if (dis[j] > mat[cid][j] + dis[cid]) {
					dis[j] = mat[cid][j] + dis[cid];
					//更新最大人手
					hmat[cid][j] = hmat[cid][j] + hand[cid];
					//如果目的地是终点
					if (j == C2) {
						if (dis[j] < an.min_dis) {
							an.num = 1;
							an.min_dis = dis[j];
							an.max_hand = hmat[cid][j];
						}
					}
				}
				//长度不变
				else if (dis[j] == mat[cid][j] + dis[cid]) {
					//dis[j] = mat[cid][j] + dis[cid];
					//更新最大人手
					if (hmat[cid][j] < hmat[cid][j] + hand[cid])
						hmat[cid][j] = hmat[cid][j] + hand[cid];
					//如果目的地是终点，更新路径数和人手数
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