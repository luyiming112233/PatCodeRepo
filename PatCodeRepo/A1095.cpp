#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<string.h>

using namespace std;

#define slen 10

struct record {
	int time;
	char cid[slen];
	int status;
};

struct park {
	int time;
	int num;
};

bool cmp(record a, record b) {
	if (strcmp(a.cid, b.cid) != 0) {
		return (string)a.cid < (string)b.cid;
	}
	return a.time < b.time;
}

bool cmp2(record a, record b) {
	return a.time < b.time;
}

bool cmp3(string a, string b) {
	return a < b;
}

int timeTrans(int hh, int mm, int ss) {
	if (hh < 0 || hh>23 || mm < 0 || mm>60 || ss < 0 || ss>60)
		return -1;
	return hh * 3600 + mm * 60 + ss;
}

void printTime(int time) {
	int hh, mm, ss;
	hh = time / 3600;
	time %= 3600;
	mm = time / 60;
	ss = time % 60;
	printf("%02d:%02d:%02d", hh, mm, ss);
}

int main() {
	int N, M,hh,mm,ss,time;
	char cstatus[slen];
	vector<record> trecords, records;
	vector<string> longTime;
	vector<park> vp;
	map<string, int> maptime;
	map<string, int>::iterator it;
	record temp;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s %d:%d:%d %s", temp.cid, &hh, &mm, &ss, cstatus);
		time = timeTrans(hh, mm, ss);
		if (time == -1)
			continue;
		temp.time = time;
		if (strcmp(cstatus,"in")==0) {
			temp.status = 1;
		}
		else if (strcmp(cstatus, "out") == 0) {
			temp.status = 0;
		}
		else {
			continue;
		}
		trecords.push_back(temp);
	}
	sort(trecords.begin(), trecords.end(), cmp);
	temp.cid[0] = '\0';
	for (int i = 0; i < trecords.size(); i++) {
		if ((string)(temp.cid) == (string)(trecords[i].cid)) {
			//一进一出
			if (temp.status == 1 && trecords[i].status == 0) {
				records.push_back(temp);
				records.push_back(trecords[i]);
				temp.status = -1;//破坏这条临时记录
				it = maptime.find(temp.cid);
				if (it == maptime.end()) {
					maptime[temp.cid] = trecords[i].time - temp.time;
				}
				else {
					maptime[temp.cid] += (trecords[i].time - temp.time);
				}
			}
			else if (trecords[i].status == 1) {
				temp = trecords[i];
			}
		}
		else if(trecords[i].status == 1){
			temp = trecords[i];
		}
	}
	sort(records.begin(), records.end(), cmp2);
	park ptemp;
	ptemp.num = 0;
	ptemp.time = 0;
	vp.push_back(ptemp);
	for (int i = 0; i < records.size(); i++) {
		if (ptemp.time != records[i].time) {
			ptemp.time = records[i].time;
			if (records[i].status == 0) {
				ptemp.num--;
			}
			else {
				ptemp.num++;
			}
			vp.push_back(ptemp);
		}
		else {
		    if (records[i].status == 0) {
				vp[vp.size()-1].num--;
				ptemp.num--;
			}
			else {
			    vp[vp.size() - 1].num++;
				ptemp.num++;
			}
		}
	}
	ptemp.time = timeTrans(23, 59, 59);
	vp.push_back(ptemp);
	ptemp.time = timeTrans(23, 59, 59)+1;
	vp.push_back(ptemp);
	for (int i = 0; i < M; i++) {
		scanf("%d:%d:%d", &hh, &mm, &ss);
		time = timeTrans(hh, mm, ss);
		for (int j = 1; j < vp.size(); j++) {
			if (time >= vp[j - 1].time && time < vp[j].time) {
				printf("%d\n", vp[j - 1].num);
				break;
			}
		}
	}
	int maxtime = -1;
	for (it = maptime.begin(); it != maptime.end(); it++) {
		if (maxtime < it->second) {
			longTime.clear();
			longTime.push_back(it->first);
			maxtime = it->second;
		}
		else if (maxtime == it->second) {
			longTime.push_back(it->first);
		}
	}
	sort(longTime.begin(), longTime.end(), cmp3);
	for (int i = 0; i < longTime.size(); i++) {
		printf("%s ", longTime[i].c_str());
	}
	printTime(maxtime);
	return 0;
}