#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
using namespace std;

struct peo {
	int id;
	int mother, father;
	int kids[5];
	double estate, area;
	bool flag;
	peo() {
		for (int i = 0; i < 5; i++)
			kids[i] = -1;
		flag = false;
	}
};

struct family {
	int id;
	int num;
	double estate, area;
	double AVGestate, AVGarea;
};

bool cmp(family a, family b) {
	if (a.AVGarea != b.AVGarea)
		return a.AVGarea > b.AVGarea;
	return a.id < b.id;
}

bool flags[100010] = { false };
set<int> fid;
vector<peo> v;
map<int, int> m;

bool judge(peo p) {
	if (fid.find(p.id) != fid.end())
		return true;
	if (p.father != -1 && fid.find(p.father) != fid.end())
		return true;
	if (p.mother != -1 && fid.find(p.mother) != fid.end())
		return true;
	for (int i = 0; i < 5; i++) {
		if (p.kids[i] != -1 && fid.find(p.kids[i]) != fid.end())
			return true;
	}
	return false;
}

void updateFid(int id) {
	if (v[m[id]].father != -1)
		fid.insert(v[m[id]].father);
	if (v[m[id]].mother != -1)
		fid.insert(v[m[id]].mother);
	for (int i = 0; i < 5; i++) {
		if (v[m[id]].kids[i]!= -1)
			fid.insert(v[m[id]].kids[i]);
	}
}

int main() {
	vector<family> answer;
	int knum;
	int N,pid;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		peo temp;
		scanf("%d %d %d", &temp.id, &temp.father, &temp.mother);
		scanf("%d", &knum);
		for (int j = 0; j < knum; j++) {
			scanf("%d", &temp.kids[j]);
		}
		scanf("%lf %lf", &temp.estate, &temp.area);
		v.push_back(temp);
		m[temp.id] = i;
	}
	for (int i = 0; i < N; i++) {
		if (v[i].flag == true)
			continue;
		fid.clear();
		int fsize = fid.size();
		v[i].flag = true;
		fid.insert(v[i].id);
		updateFid(v[i].id);
		while(fid.size() != fsize) {
			fsize = fid.size();
			for (int tj = i; tj < N; tj++) {
				if (v[tj].flag == true)
					continue;
				if (judge(v[tj])) {
					fid.insert(v[tj].id);
					updateFid(v[tj].id);
					v[tj].flag = true;
				}
			}
		}
		family tf;
		tf.id = *fid.begin();
		tf.num = fid.size();
		tf.area = 0;
		tf.estate = 0;
		for (set<int>::iterator it = fid.begin(); it != fid.end(); it++) {
			if (m.find(*it) != m.end()) {
				tf.area += v[m[*it]].area;
				tf.estate += v[m[*it]].estate;
			}
		}
		tf.AVGarea = tf.area / tf.num;
		tf.AVGestate = tf.estate / tf.num;
		answer.push_back(tf);
	}
	sort(answer.begin(), answer.end(), cmp);
	printf("%d\n", answer.size());
	for (int i = 0; i < answer.size(); i++) {
		printf("%04d %d %.3f %.3f\n", answer[i].id, answer[i].num, answer[i].AVGestate, answer[i].AVGarea);
	}
	return 0;
}