#include<cstdio>
#include<vector>
#include<string>

using namespace std;

bool first = true,isZore=false;
int r1 = 1e8;
int r2 = 1e4;

string nums[10] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };

void printS(string s) {
	if (first) {
		printf("%s", s.c_str());
		first = false;
	}
	else {
		printf(" %s", s.c_str());
	}
}

void printN1(int n1) {
	if (n1 == 0)
		return;
}

int main() {
	int num,temp;
	vector<int> v;
	scanf("%d", &num);
	if (num == 0) {
		printf("ling");
		return 0;
	}
	if (num < 0) {
		num = -num;
		printS("Fu");
	}
	temp = num;
	while (temp) {
		v.push_back(temp % 10);
		temp /= 10;
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i] == 0) {
			isZore = true;
		}
		else {
			if (isZore) {
				printS(nums[0]);
				isZore = false;
			}
			if (i == 8) {
				printS(nums[v[i]]);
				printS("Yi");
			}
			else {
				switch (i % 4)
				{
				case 0:
					printS(nums[v[i]]);
					break;
				case 1:
					printS(nums[v[i]]);
					printS("Shi");
					break;
				case 2:
					printS(nums[v[i]]);
					printS("Bai");
					break;
				case 3:
					printS(nums[v[i]]);
					printS("Qian");
					break;
				}
			}
		}
		if (i == 4)
			printS("Wan");

	}
	return 0;
}