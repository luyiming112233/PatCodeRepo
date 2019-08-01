#include<iostream>
#include<string>
using namespace std;

int min(int a,int b){
    if(a<b)
		return a;
	else
		return b;
}

int main(){
    string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
    int len12 = min(s1.length(),s2.length());
	int len34 = min(s3.length(),s4.length());
    int i,v=0,k1,k2,k3,t1,t2;
	for(i=0;i<len12;i++){
		if(s1[i]==s2[i]){
		    v++;
			if(v==1){
				k1 = s1[i]-'A'+1;
			    if(k1<1||k1>7)
			        v--;
			}
			else{
			    t1 = s1[i]-'0';
				t2 = s1[i]-'A';
				k2=-1;
                if((t1>=0&&t1<10)){
				    k2 = t1;
				}
				if((t2>=0&&t2<14)){
				    k2 = t2+10;
				}
				if(k2!=-1)
    				break;
			}
		}
	}
	for(i=0;i<len34;i++){
		if(s3[i]==s4[i]){
            t1 = s3[i]-'a';
			t2 = s3[i]-'A';
			if((t1>=0&&t1<26)||(t2>=0&&t2<26)){
		        k3=i;
			    break;
			}
		}
	}
    //½øÈëÊä³ö
	switch(k1){
	case 1:cout<<"MON ";break;
	case 2:cout<<"TUE ";break;
	case 3:cout<<"WED ";break;
	case 4:cout<<"THU ";break;
	case 5:cout<<"FRI ";break;
	case 6:cout<<"SAT ";break;
	case 7:cout<<"SUN ";break;
	}
    if(k2<10){
	    cout<<0;
	}
	cout<<k2<<":";
	if(k3<10){
	    cout<<0;
	}
	cout<<k3;
	return 0;
}
