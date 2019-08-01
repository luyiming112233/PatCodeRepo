#include<cstdio>

int main(){
    int n,a[100010]={0},id,grade;
    scanf("%d",&n);
	while(n--){
	    scanf("%d%d",&id,&grade);
		a[id]+=grade;
	}
	int i,maxid=1,max=a[1];
	for(i=2;i<100010;i++){
		if(a[i]>max){
		    max=a[i];
			maxid=i;
		}
	}
	printf("%d %d\n",maxid,max);
	return 0;
}