#include<cstdio>
#include<vector>
using namespace std;

struct stu{
    int id;
	int d1;
	int d2;
};

vector<struct stu> stus;

void swap(int &a,int &b){
    int temp;
	temp = a;
	a = b;
	b = temp;
}

void sort(vector<int> &v){
    int i,j,size=v.size();
	//按学号排序
    for(i=0;i<size;i++){
		for(j=0;j<size-1-i;j++){
			if(stus[v[j]].id>stus[v[j+1]].id)
				swap(v[j],v[j+1]);
		}
	}

	//按德分排序
	for(i=0;i<size;i++){
		for(j=0;j<size-1-i;j++){
			if(stus[v[j]].d1<stus[v[j+1]].d1)
				swap(v[j],v[j+1]);
		}
	}

	//按总分排序
	for(i=0;i<size;i++){
		for(j=0;j<size-1-i;j++){
			if(stus[v[j]].d1+stus[v[j]].d2<stus[v[j+1]].d1+stus[v[j+1]].d2)
				swap(v[j],v[j+1]);
		}
	}
}

void display(vector<int> v){
    int size = v.size();
	for(int i=0;i<size;i++)
	    printf("%d %d %d\n",stus[v[i]].id,stus[v[i]].d1,stus[v[i]].d2);
}

int main(){
    int N,L,H,i;
	scanf("%d%d%d",&N,&L,&H);
    vector<int> v1,v2,v3,v4;
	struct stu temp;
	for(i=0;i<N;i++){
		scanf("%d%d%d",&temp.id,&temp.d1,&temp.d2);
		stus.push_back(temp);
		//判断是否过最低录取线
		if(temp.d1>=L && temp.d2>=L){
			//才德全尽
			if(temp.d1>=H && temp.d2>=H){
				v1.push_back(i);
			}
			//德胜才
			else if(temp.d1>=H){
				v2.push_back(i);
			}
			//“才德兼亡”但尚有“德胜才”
			else if(temp.d1>=temp.d2){
			    v3.push_back(i);
			}
			else
			    v4.push_back(i);
		}
	}
    printf("%d\n",v1.size()+v2.size()+v3.size()+v4.size());
    sort(v1);
    sort(v2);
    sort(v3);
    sort(v4);
    display(v1);
    display(v2);
    display(v3);
    display(v4);
    return 0;
}