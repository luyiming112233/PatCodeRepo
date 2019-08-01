#include<cstdio>
#include<vector>
using namespace std;

int main() {
	char str1[100], str2[100];
	vector<char> v;
	scanf("%s", str1);
	scanf("%s", str2);
	int i = 0, j, t;
	bool isnew;
	//将小写字母转为大写
	while (str1[i] != '\0') {
		t = str1[i] - 'a';
		if (t >= 0 && t < 26)
			str1[i] = str1[i] - 32;
		i++;
	}
	i = 0;
	while (str2[i] != '\0') {
		t = str2[i] - 'a';
		if (t >= 0 && t < 26)
			str2[i] = str2[i] - 32;
		i++;
	}

	i = 0;
	while (str1[i] != '\0') {
		isnew = true;
		for (j = 0; j < v.size(); j++) {
			if (v[j] == str1[i]) {
				isnew = false;
				break;
			}
		}
		if (isnew)
			v.push_back(str1[i]);
		i++;
	}
	i = 0;
	while (str2[i] != '\0') {
		for (j = 0; j < v.size(); j++) {
			if (v[j] == str2[i]) {
				v.erase(v.begin() + j);
				break;
			}
		}
		i++;
	}

	for (i = 0; i < v.size(); i++) {
		printf("%c", v[i]);
	}
	printf("\n");
	return 0;
}