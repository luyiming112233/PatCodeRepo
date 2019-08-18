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

void Insert_Sort(vector<int> &v, vector<int> &nums) {
	int N = v.size();
	int i;
	for (int P = 1; P < N; P++) {
		isInsert = judge(v, nums);
		int temp = v[P];
		for (i = P; i > 0 && v[i - 1] > temp; i--)
			v[i] = v[i - 1];
		v[i] = temp;
		if (isInsert && !judge(v, nums))
			break;
	}
}

void downAdjust(vector<int> &v, int i, int N) {
	int j = 2 * i + 1;
	while (j < N) {
		if (j + 1 < N && v[j + 1] > v[j])
			j++;
		if (v[i] < v[j]) {
			swap(v[i], v[j]);
			i = j;
			j = 2 * i + 1;
		}
		else {
			break;
		}
	}
}

void Heap_Sort(vector<int> &v, vector<int> &nums) {
	int N = v.size();
	for (int i = N / 2; i >= 0; i--)
		downAdjust(v, i, N);
	for (int i = N - 1; i >= 0; i--) {
		bool flag = judge(v, nums);
		swap(v[0], v[i]);
		downAdjust(v, 0, i);
		if (flag)
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
	Insert_Sort(temp, nums);
	if (isInsert) {
		printf("Insertion Sort\n");
		display(temp);
	}
	else {
		printf("Heap Sort\n");
		Heap_Sort(s, nums);
		display(s);
	}
	return 0;
}