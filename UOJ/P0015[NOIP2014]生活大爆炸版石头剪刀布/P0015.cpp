//UOJ P0015 [NOIP2014]生活大爆炸版石头剪刀布
#include <iostream>
using namespace std;
int a[205]={0},b[205]={0},ansa=0,ansb=0;
int g[5][5]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int main(){
	int N,Na,Nb;
	cin>>N>>Na>>Nb;
	for(int i=0; i<Na; i++) cin>>a[i];
	for(int i=0; i<Nb; i++) cin>>b[i];
	for(int i=0; i<N; i++){
		if(g[a[i%Na]][b[i%Nb]]==1) ansa++;
		if(g[b[i%Nb]][a[i%Na]]==1) ansb++;
		}
	cout<<ansa<<' '<<ansb<<endl;
	return 0;
	}
