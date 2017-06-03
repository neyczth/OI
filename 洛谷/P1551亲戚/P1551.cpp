//Âå¹È P1551 Ç×ÆÝ
#include <iostream>
using namespace std;
int fa[5005]={0};
int find(int n){
	if(fa[n]!=n) fa[n]=find(fa[n]);
	return fa[n];
	}
int main(){
	int N,M,P,x,y;
	cin>>N>>M>>P;
	for(int i=1; i<=N; i++) fa[i]=i;
	for(int i=1; i<=M; i++){
		cin>>x>>y;
		fa[find(x)]=find(y);
		}
	for(int i=1; i<=N; i++) fa[i]=find(i);
	for(int i=1; i<=P; i++){
		cin>>x>>y;
		if(find(x)==find(y)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		}
	return 0;
	}
