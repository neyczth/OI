//NOI题库 1.10 06 整数奇偶排序
#include <iostream>
#include <algorithm>
using namespace std;
int a[10]={0};
bool cmp(int x,int y){
	if(x%2==1&&y%2==1) return x>y;
	if(x%2==1&&y%2==0) return 1;
	if(x%2==0&&y%2==1) return 0;
	return x<y;
	}
int main(){
	for(int i=0; i<10; i++) cin>>a[i];
	sort(a,a+10,cmp);
	for(int i=0; i<10; i++) cout<<a[i]<<' ';
	cout<<endl;
	return 0;
	}

