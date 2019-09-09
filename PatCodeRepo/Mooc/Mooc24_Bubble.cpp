#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

void swap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

/*void Bubble_Sort(vector<int> &v) {
	int N = v.size();
	bool flag;
	for (int P = N; P >= 0; P--) {
		flag = true;
		for (int i = 0; i < P - 1; i++) {
			if (v[i] > v[i + 1]) {
				swap(v[i], v[i + 1]);
				flag = false;
			}
		}
		if (flag)
			break;
	}
}*/
void Bubble_Sort(vector<int> &v) {
	bool flag;
	int len = v.size() - 1;
	for (int P = len; P > 0; P--) {
		flag = true;
		for (int i = 0; i < P; i++) {
			if (v[i] > v[i + 1]) {
				swap(v[i], v[i + 1]);
				flag = false;
			}
		}
		if (flag) break;
	}
}


void Insert_Sort(vector<int> &v) {
	int N = v.size();
	int i;
	for (int P = 1; P < N; P++) {
		int temp = v[P];
		for (i = P; i > 0 && temp < v[i - 1]; i--)
			v[i] = v[i - 1];
		v[i] = temp;
	}
}

void Merge(vector<int> &v,vector<int> &temp,int LS,int LE,int RS,int RE) {
	int cLS = LS,index=LS;
	while (LS <= LE && RS <= RE) {
		if (v[LS] <= v[RS])
			temp[index++] = v[LS++];
		else
			temp[index++] = v[RS++];
	}
	while (LS <= LE)
		temp[index++] = v[LS++];
	while (RS <= RE)
		temp[index++] = v[RS++];
	for (int i = cLS; i <= RE; i++)
		v[i] = temp[i];
}

void Merge_Sort(vector<int> &v) {
	vector<int> temp = v;
	int N = v.size();
	int i;
	for (int L = 1; L < N; L *= 2) {
		for (i = 0; i < N - 2 * L; i += 2 * L) {
			Merge(v, temp, i, i + L - 1, i + L, i + 2 * L - 1);
		}
		if (i + L < N)
			Merge(v, temp, i, i + L - 1, i + L, N - 1);
	}
}

void downAdjust(vector<int> &v, int i, int N) {
	int j = 2 * i+1;
	while (j < N) {
		//右儿子比左儿子大
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

void Heap_Sort(vector<int> &v) {
	int N = v.size();
	//建堆
	for (int i = N / 2; i >= 0; i--)
		downAdjust(v, i, N);
	for (int i = N - 1; i > 0; i--) {
		swap(v[i], v[0]);
		downAdjust(v, 0, i);//调整堆
	}
}

int Partition(vector<int> &v,int left,int right) {
	int temp = v[left];
	while (left < right) {
		while (left<right && v[right]>temp)
			right--;
		v[left] = v[right];
		while (left < right && v[left] <= temp)
			left++;
		v[right] = v[left];
	}
	v[left] = temp;
	return left;
}

void D_quicksort(vector<int> &v,int left,int right) {
	if (left < right) {
		int center = Partition(v, left, right);
		D_quicksort(v, left, center - 1);
		D_quicksort(v, center + 1, right);
	}
}

void Quick_Sort(vector<int> &v) {
	int N = v.size();
	D_quicksort(v, 0, N - 1);
}

int main() {
	int N,num;
	vector<int> v;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	Bubble_Sort(v);
	for (int i = 0; i < v.size(); i++) {
		if (i == 0) printf("%d", v[i]);
		else printf(" %d", v[i]);
	}
	return 0;
}
