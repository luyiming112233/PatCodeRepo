#include<cstdio>

int main(){
    int n,i,j;
	char c;
	scanf("%d %c",&n,&c);
    int m = (n+1)/2;

    for(i=0;i<n;i++)
		printf("%c",c);
	printf("\n");

	for(i=1;i<m-1;i++){
	    printf("%c",c);

        for(j=1;j<n-1;j++)
            printf(" ");

        printf("%c\n",c);
	}

    for(i=0;i<n;i++)
		printf("%c",c);
	printf("\n");
	return 0;
}