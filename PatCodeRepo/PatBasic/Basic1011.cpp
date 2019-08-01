#include<iostream>
using namespace std;

int main(){
    int n;
	//long long int a,b,c;
	_int64 a,b,c;
	cin>>n;
    for(int i=0;i<n;i++){
	    //cin>>a>>b>>c;
		scanf("%I64d",&a);
		scanf("%I64d",&b);
		scanf("%I64d",&c);
		cout<<"Case #"<<i+1<<": ";
		if(a+b>c)
			cout<<"true"<<endl;
		else
			cout<<"false"<<endl;
	}
	return 0;
}