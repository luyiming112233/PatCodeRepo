#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define size 50

int main() {
	char pass[size], input[size];
	int time;
	scanf("%s", pass);
	scanf("%d", &time);
	getchar();
	while (true) {
		cin.getline(input, size);
		if (input[0] == '#' && strlen(input)==1)
			break;
		if (strcmp(pass, input) == 0) {
			printf("Welcome in\n");
			break;
		}
		else {
			printf("Wrong password: %s\n", input);
			time--;
			if (time == 0) {
				printf("Account locked\n");
				break;
			}
		}
	}
	return 0;
}