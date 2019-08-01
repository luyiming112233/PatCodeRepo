#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int a[10]={0},i,j;
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
    for(i=1;i<10;i++){
		if(a[i]>0){
		    a[i]--;
			printf("%d",i);
		    break;
		}
	}
    for(i=0;i<10;i++){
	    for(j=0;j<a[i];j++)
			printf("%d",i);
	}
	printf("\n");
	return 0;
}
