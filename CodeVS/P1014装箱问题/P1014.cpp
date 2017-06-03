//CodeVS P1014 ◊∞œ‰Œ Ã‚
#include <iostream>
#include <algorithm>
using namespace std;
int v[35]={0},dp[20005]={0};
int main(){
	int V,N;
	cin>>V>>N;
	for(int i=1; i<=N; i++) cin>>v[i];
	for(int i=1; i<=N; i++)
		for(int j=V; j>=v[i]; j--)
			dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
	cout<<V-dp[V]<<endl;
	return 0;
	}
