#include<cstdio>

int getnum(int n,int dn){
    int num=0;
	while(n>0){
	    if(n%10==dn)
			num++;
		n/=10;
	}
	return num;
}

int main(){
    int a,da,b,db,num1,num2,sum=0,i,wei;
	scanf("%d%d%d%d",&a,&da,&b,&db);
    num1 = getnum(a,da);
	num2 = getnum(b,db);
	wei = 1;
	for(i=0;i<num1;i++){
	    sum+=(wei*da);
		wei*=10;
	}
    wei = 1;
	for(i=0;i<num2;i++){
	    sum+=(wei*db);
		wei*=10;
	}
	printf("%d\n",sum);
	return 0;
}