#include<cstdio>

int main(){
    char str[1001];
	int b;
	scanf("%s %d",str,&b);
    int temp = 0,i;

    temp = str[0]-'0';
	if(temp/b!=0)
        printf("%d",temp/b);
	temp%=b;

	for(i=1;i<1001;i++){
		if(str[i]=='\0')
			break;
        temp = temp*10+str[i]-'0';
		printf("%d",temp/b);
		temp%=b;
	}
	if(i==1&& str[0]-'0'<b)
		printf("%d",0);

	printf(" %d\n",temp);
	return 0;
}