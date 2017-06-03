//Tyvj P1016 ◊∞œ‰Œ Ã‚
#include <iostream>
#include <algorithm>
using namespace std;
int dp[20005]={0};
int main(){
	int maxV,N,vi;
	cin>>maxV>>N;
	for(int i=1; i<=N; i++){
		cin>>vi;
		for(int v=maxV; v>=vi; v--) dp[v]=max(dp[v],dp[v-vi]+vi);
		}
	cout<<maxV-dp[maxV]<<endl;
	return 0;
	}
