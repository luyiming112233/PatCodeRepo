#include<iostream>
using namespace std;

int main(){
    int m,n,i,j,num=0,size=1000000;
	cin>>m>>n;
    int *arry = new int [size];
	for(i=0;i<size;i++)
		arry[i] = 0;
	arry[0] = 1;
	arry[1] = 1;

	for(i=2;i*i<size;i++){
		for(j=2*i;j<size;j+=i){
		    arry[j] = 1;
		}
	}

	for(i=1;i<size;i++){
		if(arry[i]==0){
		    num++;
			//�ж��Ƿ��ڷ�Χ��
			if(num>=m){
			    //�ж��Ƿ���Ҫ�ո���߻���
                if((num-m)%10==0){
				    if(num-m!=0)
						cout<<endl;
					cout<<i;
				}
            else
			    cout<<" "<<i;
			}
			if(num==n)
				break;
		}
	}
    return 0;
}