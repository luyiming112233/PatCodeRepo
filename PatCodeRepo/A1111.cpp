#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 510
#define INF 1000000

struct answer {
	int time;
	int dis;
	vector<int> path;
};

bool connect[maxn];
int minDis[maxn];
int minTime[maxn];
int disMat[maxn][maxn];
int timeMat[maxn][maxn];
int disPath[maxn];

vector<int> timePath[maxn];
vector<int> tempPath;
answer disAnswer;
answer timeAnswer;

void createPath(vector<int> &v,int end,int path[maxn]) {
	while (end != -1) {
		v.push_back(end);
		end = path[end];
	}
}

bool answerJudge(answer a,answer b) {
	if (a.path.size() != b.path.size())
		return false;
	for (int i = 0; i < a.path.size(); i++) {
		if (a.path[i] != b.path[i])
			return false;
	}
	return true;
}

void displayPath(vector<int> v) {
	bool first = true;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (first) {
			printf("%d", v[i]);
			first = false;
		}
		else {
			printf(" -> %d", v[i]);
		}
	}
}

void createTimePath(int s,int sss) {
	tempPath.push_back(s);
	if (sss == s) {
		if (timeAnswer.path.size() == 0 || tempPath.size() < timeAnswer.path.size()) {
			timeAnswer.path.assign(tempPath.begin(), tempPath.end());
		}
	}
	if (timePath[s].size() != 0) {
		for (int i = 0; i < timePath[s].size(); i++) {
			createTimePath(timePath[s][i],sss);
		}
	}
	tempPath.pop_back();
}

int main() {
	fill(connect, connect + maxn, false);
	fill(minDis, minDis + maxn, INF);
	fill(minTime, minTime + maxn, INF);
	fill(disMat[0], disMat[0] + maxn * maxn,INF);
	fill(timeMat[0], timeMat[0] + maxn * maxn, INF);
	fill(disPath, disPath + maxn, -1);
	//fill(timePath, timePath + maxn, -1);
	int N, M,start,end;
	int a, b, one, il, it,now;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d %d", &a, &b, &one, &il, &it);
		disMat[a][b] = il;
		timeMat[a][b] = it;
		if (one == 0) {
			disMat[b][a] = il;
			timeMat[b][a] = it;
		}
	}
	scanf("%d %d", &start, &end);
	minDis[start] = 0;
	minTime[start] = 0;
	for (int ni = 0; ni < N; ni++) {
		now = -1;
		int mD = INF;
		for (int i = 0; i < N; i++) {
			if (connect[i] == false && mD > minDis[i]) {
				mD = minDis[i];
				now = i;
			}
		}
		if (now == -1)
			break;
		connect[now] = true;
		for (int i = 0; i < N; i++) {
			if (connect[i] == false && minDis[i] > disMat[now][i] + minDis[now]) {
				minDis[i] = disMat[now][i] + minDis[now];
				minTime[i] = timeMat[now][i]+minTime[now];
				disPath[i] = now;
				if (i == end) {
					vector<int> tpath;
					createPath(tpath, end, disPath);
					disAnswer.dis = minDis[end];
					disAnswer.time = minTime[end];
					disAnswer.path = tpath;
				}
			}
			else if (connect[i] == false && minDis[i] == disMat[now][i] + minDis[now]) {
				if (minTime[i] > timeMat[now][i] + minTime[now]) {
					minTime[i] = timeMat[now][i] + minTime[now];
					disPath[i] = now;
					if (i == end) {
						vector<int> tpath;
						createPath(tpath, end, disPath);
						//if (disAnswer.path.size() == 0 || disAnswer.path.size() > tpath.size()) {
						    disAnswer.dis = minDis[end];
						    disAnswer.time = minTime[end];
						    disAnswer.path = tpath;
						//}
					}
				}
			}
		}
	}
	fill(connect, connect + maxn, false);
	fill(minDis, minDis + maxn, INF);
	fill(minTime, minTime + maxn, INF);
	minDis[start] = 0;
	minTime[start] = 0;
	for (int ni = 0; ni < N; ni++) {
		now = -1;
		int mT = INF;
		for (int i = 0; i < N; i++) {
			if (connect[i] == false && mT > minTime[i]) {
				mT = minTime[i];
				now = i;
			}
		}
		if (now == -1)
			break;
		connect[now] = true;
		for (int i = 0; i < N; i++) {
			if (connect[i] == false && minTime[i] > timeMat[now][i] + minTime[now]) {
				minDis[i] = disMat[now][i] + minDis[now];
				minTime[i] = timeMat[now][i] + minTime[now];
				timePath[i].clear();
				timePath[i].push_back(now);
			}
			else if (connect[i] == false && minTime[i] == timeMat[now][i] + minTime[now]) {
				timePath[i].push_back(now);
			}
		}
	}

	timeAnswer.time = minTime[end];
	createTimePath(end,start);

	if(answerJudge(disAnswer, timeAnswer)) {
		printf("Distance = %d; Time = %d: ", disAnswer.dis, disAnswer.time);
		displayPath(disAnswer.path);
	}
	else {
		printf("Distance = %d: ", disAnswer.dis);
		displayPath(disAnswer.path);
		printf("\n");
		printf("Time = %d: ", timeAnswer.time);
		displayPath(timeAnswer.path);
	}
	return 0;
}