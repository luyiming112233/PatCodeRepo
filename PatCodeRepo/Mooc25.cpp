#include<cstdio>
#include<vector>
using namespace std;

bool isInsert = false;

bool judge(vector<int> &v, vector<int> &nums) {
	for (int i = 0; i < v.size(); i++)
		if (v[i] != nums[i])
			return false;
	return true;
}

void swap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

void display(vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		if (i == 0)
			printf("%d", v[i]);
		else
			printf(" %d", v[i]);
	}
}

void Insert_Sort(vector<int> &v,vector<int> &nums) {
	int N = v.size();
	int i;
	for (int P = 1; P < N; P++) {
		isInsert = judge(v, nums);
		int temp = v[P];
		for (i = P; i > 0 && v[i-1]>temp; i--) 
			v[i] = v[i - 1];
		v[i] = temp;
		if (isInsert && !judge(v,nums))
			break;
	}
}

void merge(vector<int> &v, vector<int> &temp,int LS,int LE,int RS,int RE) {
	int CLS = LS;
	int ts = LS;
	while (LS <= LE && RS <= RE) {
		if (v[LS] <= v[RS])
			temp[ts++] = v[LS++];
		else
			temp[ts++] = v[RS++];
	}
	while (LS <= LE) {
		temp[ts++] = v[LS++];
	}
	while (RS <= RE) {
		temp[ts++] = v[RS++];
	}
	for (int i = CLS; i <= RE; i++)
		v[i] = temp[i];
}

void Merge_Sort(vector<int> &v,vector<int> &nums) {
	vector<int> temp = v;
	int N = v.size();
	int i;
	//L<N
	for (int L = 1; L < N; L *= 2) {
		bool flag = judge(v, nums);
		for (i = 0; i < N - 2 * L; i += 2 * L) {
			merge(v, temp, i, i + L - 1, i + L, i + 2 * L - 1);
		}
		if (i + L < N) {
			merge(v, temp, i, i + L - 1, i + L, N - 1);
		}
		if (flag && !judge(v, nums))
			break;
	}
}

int main() {
	vector<int> nums, s, temp;
	int N, num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		s.push_back(num);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		nums.push_back(num);
	}
	temp = s;
	Insert_Sort(temp,nums);
	if (isInsert) {
		printf("Insertion Sort\n");
		display(temp);
	}
	else {
		Merge_Sort(s, nums);
		printf("Merge Sort\n");
		display(s);
	}
	return 0;
}
