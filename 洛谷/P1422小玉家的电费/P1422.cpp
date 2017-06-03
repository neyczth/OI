//洛谷 P1422 小玉家的电费
#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	int n;
	double ans=0;
	cin>>n;
	ans+=n*0.4463;
	n-=150;
	if(n>0){
		ans+=n*0.02;
		n-=250;
		if(n>0) ans+=n*0.1;
		}
	printf("%.1lf\n",ans);
	return 0;
	}
