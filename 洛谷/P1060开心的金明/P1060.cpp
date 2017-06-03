//洛谷 P1060 开心的金明 
#include <iostream>
using namespace std;
int dp[30][30005]={0};
struct node{
	int jg,zyd;
	node(){
		jg=0;
		zyd=0;
		}
	}wp[30];
int main(){
	int N,M;
	cin>>N>>M;
	for(int i=1; i<=M; i++) cin>>wp[i].jg>>wp[i].zyd;
	for(int i=1; i<=M; i++)
		for(int j=1; j<=N; j++){
			dp[i][j]=dp[i-1][j]; 
			if(j>=wp[i].jg) dp[i][j]=max(dp[i][j],dp[i-1][j-wp[i].jg]+wp[i].zyd*wp[i].jg);
			}
	cout<<dp[M][N]<<endl;
	return 0;
	}
