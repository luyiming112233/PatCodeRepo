#include<cstdio>
#include<vector>
using namespace std;

#define maxn 110

vector<int> v, vs,s1,a;
int N;

void swap(int &a, int &b) {
	int c = a;
	a = b, b = c;
}

void adjust(int low, int high) {
	int i = low, j = 2 * i + 1;
	while (j <= high) {
		if (j + 1 <= high && a[j] < a[j + 1]) j++;
		if (a[i] < a[j]) {
			swap(a[i], a[j]);
			i = j, j = 2 * i + 1;
		}
		else
			break;
	}
}

bool HeapSort() {
	for (int i = N / 2; i >= 0; i--)
		adjust(i, N - 1);
	bool flag = false;
	for (int i = N-1; i>0; i--) {
		swap(a[0], a[i]);
		adjust(0, i - 1);
		if (flag && a != vs) break;
		if (!flag && a == vs) flag = true;
	}
	return flag;
}

bool insertSort(vector<int> &s) {
	bool flag = false;
	for (int i = 1; i < s.size(); i++) {
		int j,temp=s[i];
		for (j = i; j > 0; j--) {
			if (s[j - 1] > temp) s[j] = s[j - 1];
			else break;
		}
		s[j] = temp;
		if (flag && s != vs) break;
		if (!flag && s == vs) flag = true;
	}
	return flag;
}

void printV(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		if (i == 0) printf("%d", v[i]);
		else printf(" %d", v[i]);
	}
}

int main() {
	int num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		vs.push_back(num);
	}
	s1 = v;
	if (insertSort(s1)) {
		printf("Insertion Sort\n");
		printV(s1);
	}
	else {
		printf("Heap Sort\n");
		a = v;
		HeapSort();
		printV(a);
	}
	return 0;
}