#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main(){
    int n,num,i;
	vector<int> v1,v2,v3,v4,v5;
	cin>>n;
	//�����ַ��䵽��Ӧ��λ��
    for(i=0;i<n;i++){
	    cin>>num;
		switch(num%5){
		case 0:
			if(num%2==0)
    			v1.push_back(num);
			break;
		case 1:v2.push_back(num);break;
		case 2:v3.push_back(num);break;
		case 3:v4.push_back(num);break;
		case 4:v5.push_back(num);break;
		}
	}    
	//����A1
	if(v1.size()==0)
		cout<<"N";
	else{
	    int a1=0;
		for(i=0;i<v1.size();i++)
			a1+=v1[i];
		cout<<a1;
	}
	cout<<" ";
	//����A2
	if(v2.size()==0)
		cout<<"N";
	else{
		int a2=0;
		for(i=0;i<v2.size();i++){
		    if(i%2==0)
				a2+=v2[i];
			else
				a2-=v2[i];
		}
		cout<<a2;
	}
	cout<<" ";
    //����A3
	if(v3.size()==0)
		cout<<"N";
	else{
	    cout<<v3.size();
	}
	cout<<" ";
	//����A4
	if(v4.size()==0)
		cout<<"N";
	else{
		//ʹ��intת��
		int ia4=0;
		double a4;
		for(i=0;i<v4.size();i++){
		    ia4+=v4[i];
		}
		ia4=ia4*100/v4.size();
		if(ia4%10>4){
		    ia4=ia4+10;
		}
		ia4/=10;
		a4=(1.0)*ia4/10;
		cout<<a4;
	}
	cout<<" ";
	//����A5
	if(v5.size()==0)
		cout<<"N";
	else{
	    int a5=v5[0];
        for(i=1;i<v5.size();i++){
		    if(a5<v5[i])
				a5=v5[i];
		}
		cout<<a5;
	}
	cout<<endl;
	return 0;

}
