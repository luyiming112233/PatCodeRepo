#include<cstdio>
#include<vector>
using namespace std;

int main(){
    int a,b,d,sum,i;
	scanf("%d%d%d",&a,&b,&d);
	vector<int> answer;
    if(d==10)
		printf("%d\n",a+b);
	else if(a+b==0)
        printf("%d\n",0);
	else{
	    sum=a+b;
		while(sum!=0){
		    answer.push_back(sum%d);
			sum/=d;
		}
        for(i=0;i<answer.size();i++){
		    printf("%d",answer[answer.size()-1-i]);
		}
		printf("\n");
	}
	return 0;
}