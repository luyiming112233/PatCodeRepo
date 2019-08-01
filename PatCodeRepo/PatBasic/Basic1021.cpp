#include<cstdio>

int main(){
    char str[1001];
	scanf("%s",str);
	int a[10]={0},i;
    for(i=0;i<1001;i++){
	    if(str[i]=='\0')
			break;
		a[str[i]-'0']++;
	}
	for(i=0;i<10;i++){
	    if(a[i]>0)
			printf("%d:%d\n",i,a[i]);
	}
	return 0;
}