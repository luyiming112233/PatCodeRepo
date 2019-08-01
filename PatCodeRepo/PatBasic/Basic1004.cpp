#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	int n, i, grade, maxid = 0, minid = 0;
	vector<string> vname, vid;
	vector<int> vgrade;
	string name, id;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> name >> id >> grade;
		vname.push_back(name);
		vid.push_back(id);
		vgrade.push_back(grade);
	}

	for (i = 1; i < n; i++) {
		if (vgrade[i] > vgrade[maxid])
			maxid = i;
		if (vgrade[i] < vgrade[minid])
			minid = i;
	}
	cout << vname[maxid] << " " << vid[maxid] << endl;
	cout << vname[minid] << " " << vid[minid] << endl;
	return 0;
}