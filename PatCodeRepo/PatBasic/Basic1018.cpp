#include<cstdio>

int main(){
    int n,i,a1[3]={0},a2[3]={0},pin=0;
	char c1,c2,ch[3];
    scanf("%d",&n);
	for(i=0;i<n;i++){
	    scanf("\n%c %c",&c1,&c2);
        if(c1==c2)
			pin++;
		else{
			if(c1=='C' && c2=='J'){
			    a1[0]++;
			}
            else if(c1=='J' && c2=='B'){
			    a1[1]++;
			}
			else if(c1=='B' && c2=='C'){
			    a1[2]++;
			}
			else if(c2=='C' && c1=='J'){
			    a2[0]++;
			}
            else if(c2=='J' && c1=='B'){
			    a2[1]++;
			}
			else if(c2=='B' && c1=='C'){
			    a2[2]++;
			}
		}
	}
	printf("%d %d %d\n",a1[0]+a1[1]+a1[2],pin,a2[0]+a2[1]+a2[2]);
	printf("%d %d %d\n",a2[0]+a2[1]+a2[2],pin,a1[0]+a1[1]+a1[2]);
    
	if(a1[2]>=a1[0]&&a1[2]>=a1[1]){
	    printf("%c",'B');
	}
	else if(a1[0]>=a1[1]&&a1[0]>a1[2]){
	    printf("%c",'C');
	}else
		printf("%c",'J');

	if(a2[2]>=a2[0]&&a2[2]>=a2[1]){
	    printf(" %c",'B');
	}
	else if(a2[0]>=a2[1]&&a2[0]>a2[2]){
	    printf(" %c",'C');
	}else
		printf(" %c",'J');
    return 0;
}