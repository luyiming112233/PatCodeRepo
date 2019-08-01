#include<cstdio>
#include<set>
using namespace std;

int main() {
	int n,sum,num;
	set<int> s;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &num);
		sum = 0;
		while (num!=0)
		{
			sum += (num % 10);
			num /= 10;
		}
		s.insert(sum);
	}
	printf("%d\n", s.size());
	int k = 0;
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		if (k == 0) {
			printf("%d", *it);
			k++;
		}
		else
			printf(" %d", *it);
	}
	printf("\n");
	return 0;
}