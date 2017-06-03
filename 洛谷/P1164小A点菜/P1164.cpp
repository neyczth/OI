//Âå¹È P1164 Ð¡Aµã²Ë 
#include <iostream>
using namespace std;
int dp[105][10005]={0},a[105]={0};
int main(){
	int N,M;
	cin>>N>>M;
	for(int i=1; i<=N; i++) cin>>a[i];
	for(int i=0; i<=N; i++) dp[i][0]=1;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++){
			dp[i][j]=dp[i-1][j];
			if(j>=a[i]) dp[i][j]+=dp[i-1][j-a[i]];
			}
	cout<<dp[N][M]<<endl;
	return 0;
	}
