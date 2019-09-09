#include<cstdio>
#include<iostream>
using namespace std;

struct node {
	int zz, kk;
};

int main() {
	node a, b;
	a.zz = 11, a.kk = 22, b.kk = 0, b.zz = 1;
	swap(a, b);
	//printf("%d %d", a, b);
	return 0;
}