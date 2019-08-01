#include<cstdio>
#include<cstring>

bool judge60(int n) {
	if (n >= 0 && n < 60)
		return true;
	return false;
}

bool judge24(int n) {
	if (n >= 0 && n < 24)
		return true;
	return false;
}

int main() {
	int M, ihh, imm, iss, ohh, omm, oss, in=1000000,out=-1;
	int tin, tout;
	char str[16],instr[16],outstr[16];
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%s", str);
		scanf("%d:%d:%d", &ihh, &imm, &iss);
		scanf("%d:%d:%d", &ohh, &omm, &oss);
		tin = ihh * 10000 + imm * 100 + iss;
		tout = ohh * 10000 + omm * 100 + oss;

		if (tin < in) {
			in = tin;
			strcpy(instr, str);
		}
		
		if (tout > out) {
			out = tout;
			strcpy(outstr, str);
		}
	}
	printf("%s %s", instr, outstr);
	return 0;
}