#include<cstdio>
#include<vector>
using namespace std;

int main(){
    char str[10000],c,fu;
    vector<char> v;
	scanf("%s",str);
	int i,z=0,j;
    //输出符号
	printf("%c",str[0]);
    //读取整数部分
	c = str[1];
    v.push_back(c);
    i=3;
	while(str[i]!='E'){
	    v.push_back(str[i]);
		i++;
	}
	//读取指数位的符号
	i++;
	fu = str[i];
    //计算指数的值
	i++;
	while(str[i]!='\0'){
	    z=z*10+str[i]-'0';
		i++;
	}
	if(fu=='+'){
		if(v.size()-1>z){
			for(j=0;j<v.size();j++){
			    printf("%c",v[i]);
				if(j==z)
					printf(".");
			}
		}else{
		    for(j=0;j<v.size();j++)
				printf("%c",v[i]);
			for(j=0;j<z+1-v.size();j++)
                printf("%c",'0');
		}
	}else{
	    printf("%s","0.");
		for(j=1;j<z;j++)
			printf("%c",'0');
        for(j=0;j<v.size();j++)
			printf("%c",v[i]);
	}
	printf("%c",'\n');
	return 0;
}