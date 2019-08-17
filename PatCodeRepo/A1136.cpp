#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 1010

vector<int> A, B, C;

bool judge(vector<int> v) {
	for (int i = 0; i < v.size() / 2; i++) {
		if (v[i] != v[v.size() - 1 - i])
			return false;
	}
	return true;
}

void printPalind(vector<int> v) {
	for (int i = 0; i < v.size(); i++)
		printf("%d", v[i]);
	printf(" is a palindromic number.\n");
}

void printABC() {
	for (int i = 0; i < A.size(); i++)
		printf("%d", A[i]);
	printf(" + ");
	for (int i = 0; i < B.size(); i++)
		printf("%d", B[i]);
	printf(" = ");
	for (int i = 0; i < C.size(); i++)
		printf("%d", C[i]);
	printf("\n");
}

int main() {
	char str[maxn];
	int step = 0,num,jin=0;
	scanf("%s", &str);
	for (int i = 0; i < maxn; i++) {
		if (str[i] == '\0')
			break;
		A.push_back(str[i] - '0');
	}
	for (step = 0; step < 10; step++) {
		if (step == 0 && judge(A)) {
			printPalind(A);
			break;
		}
		B = A;
		reverse(B.begin(), B.end());
		C.clear();
		jin = 0;
		for (int i = 0; i < A.size(); i++) {
			num = A[i] + B[i]+jin;
			C.push_back(num % 10);
			if (num >= 10) {
				jin = 1;
			}
			else {
				jin = 0;
			}
		}
		if (jin == 1)
			C.push_back(1);
		reverse(C.begin(), C.end());
		printABC();
		if (judge(C)) {
			printPalind(C);
			break;
		}
		A = C;
	}
	if (step >= 10) {
		printf("Not found in 10 iterations.");
	}
	return 0;
}