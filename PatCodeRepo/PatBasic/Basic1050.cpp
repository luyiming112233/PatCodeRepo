#include<cstdio>
#include<algorithm>
using namespace std;

bool emp(int a, int b) {
	return a > b;
}

int getn(int N) {
	int n=1,diff=N;
	for (int i = 1; i*i <= N; i++) {
		if (N%i == 0 && N/i-i<diff) {
			n = i;
		}
	}
	return n;
}

int main() {
	int n,m,N;
	while (~scanf("%d",&N))
	{
        //����n��m
		n = getn(N);
		m = N / n;
		//�½�����
		int *a = new int[N],**mat=new int*[m];
		for (int i = 0; i < m; i++)
			mat[i] = new int[n];
		//��������
		for (int i = 0; i < N; i++) 
			scanf("%d", &a[i]);
		sort(a, a + N,emp);
		int ii = 0, jj = 0,up_m=0,down_m=m,left_n=-1,right_n=n,k=0;
		for (int i = 0; i < N; i++){
			mat[ii][jj] = a[i];
			switch (k)
			{
			case 0:
				if (jj + 1 == right_n) {
					ii++;//�����ƶ�
					right_n--;//�߽�仯
					k = 1;//����仯
				}
				else {
					jj++;
				}
				break;
			case 1:
				if (ii + 1 == down_m) {
					jj--;//�����ƶ�
					down_m--;//�߽�仯
					k = 2;//����仯
				}
				else {
					ii++;
				}
				break;
			case 2:
				if (jj - 1 == left_n) {
					ii--;//�����ƶ�
					left_n++;//�߽�仯
					k = 3;//����仯
				}
				else {
					jj--;
				}
				break;
			case 3:
				if (ii - 1 == up_m) {
					jj++;//�����ƶ�
					up_m++;//�߽�仯
					k = 0;//����仯
				}
				else {
					ii--;
				}
				break;
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (j != 0) {
					printf(" %d", mat[i][j]);
				}
				else {
					printf("%d", mat[i][j]);
				}
			}
			printf("\n");
		}
		return 0;
	}
}