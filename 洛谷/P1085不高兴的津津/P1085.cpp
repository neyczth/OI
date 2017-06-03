//洛谷 P1085 不高兴的津津
#include <iostream>
#define INF 999999999
using namespace std;
int main(){
	int x,y,s,ans=0,ansx=0;
	for(int i=1; i<=7; i++){
		cin>>x>>y;
		s=x+y;
		if(s>=8&&(ans==0||s>ans)){
			ans=s;
			ansx=i;
			}
		}
	cout<<ansx<<endl;
	return 0;
	}
