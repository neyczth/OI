//CodeVS P3145 ººÅµËşÎÊÌâ 
#include <iostream>
using namespace std;
void move(int n,char A,char B,char C){
	if(n>1) move(n-1,A,C,B);
	cout<<n<<" from "<<A<<" to "<<C<<endl;
	if(n>1) move(n-1,B,A,C);
	return;
	}
int main(){
	int n,ans=1;
	cin>>n;
	for(int i=1; i<=n; i++) ans*=2;
	ans--;
	cout<<ans<<endl;
	move(n,'A','B','C');
	return 0;
	}
