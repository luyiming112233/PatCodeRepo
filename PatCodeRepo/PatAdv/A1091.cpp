#include<cstdio>
#include<queue>
using namespace std;

#define maxM 1290
#define maxN 130
#define maxL 62

struct da {
	int Li, Mi, Ni;
};

int mat[maxL][maxM][maxN] = {0};
int M, N, L, T, sum = 0;

void search(da d) {
	queue<da> q;
	int tsum = 0;
	q.push(d);
	da dt,cdt;
	mat[d.Li][d.Mi][d.Ni] = 2;
	while (!q.empty()) {
		dt = q.front();
		q.pop();
		tsum++;
		if (mat[dt.Li + 1][dt.Mi][dt.Ni] == 1) {
			cdt = dt;
			cdt.Li += 1;
			mat[dt.Li + 1][dt.Mi][dt.Ni] = 2;
			q.push(cdt);
		}
		if (mat[dt.Li - 1][dt.Mi][dt.Ni] == 1) {
			cdt = dt;
			cdt.Li -= 1;
			q.push(cdt);
			mat[dt.Li - 1][dt.Mi][dt.Ni] = 2;
		}
		if (mat[dt.Li][dt.Mi+1][dt.Ni] == 1) {
			cdt = dt;
			cdt.Mi += 1;
			q.push(cdt);
			mat[dt.Li][dt.Mi + 1][dt.Ni] = 2;
		}
		if (mat[dt.Li][dt.Mi-1][dt.Ni] == 1) {
			cdt = dt;
			cdt.Mi -= 1;
			q.push(cdt);
			mat[dt.Li][dt.Mi - 1][dt.Ni] = 2;
		}
		if (mat[dt.Li][dt.Mi][dt.Ni+1] == 1) {
			cdt = dt;
			cdt.Ni += 1;
			q.push(cdt);
			mat[dt.Li][dt.Mi][dt.Ni + 1] = 2;
		}
		if (mat[dt.Li][dt.Mi][dt.Ni-1] == 1) {
			cdt = dt;
			cdt.Ni -= 1;
			q.push(cdt);
			mat[dt.Li][dt.Mi][dt.Ni - 1] = 2;
		}
	}
	if (tsum >= T) {
		sum += tsum;
	}
}

int main() {
	da datemp;
	scanf("%d %d %d %d", &M, &N, &L, &T);
	for (int Li = 1; Li <= L; Li++) {
		for (int Mi = 1; Mi <= M; Mi++) {
			for (int Ni = 1; Ni <= N; Ni++) {
				scanf("%d", &mat[Li][Mi][Ni]);
			}
		}
	}

	for (int Li = 1; Li <= L; Li++) {
		for (int Mi = 1; Mi <= M; Mi++) {
			for (int Ni = 1; Ni <= N; Ni++) {
				if (mat[Li][Mi][Ni] == 1) {
					datemp.Li = Li;
					datemp.Mi = Mi;
					datemp.Ni = Ni;
					search(datemp);
				}
			}
		}
	}

	printf("%d", sum);
	return 0;
}