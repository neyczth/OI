//Âå¹È P1018 ³Ë»ý×î´ó
#include <cstdio>
#include <iostream> 
using namespace std;
long long p(int n){
	long long ans=1;
	while(n--) ans*=10;
	return ans;
	}
int a[45]={0};
long long dp[45][10]={0};
int main(){
	int N,K;
	long long now;
	char ch;
	cin>>N>>K;
	for(int i=1; i<=N; i++){
		cin>>ch;
		a[i]=ch-'0';
		}
	for(int i=1; i<=N; i++) dp[i][0]=dp[i-1][0]*10+a[i];
	for(int i=1; i<=N; i++){
		for(int j=1; j<=K; j++){
			for(int k=1; k<=i-1; k++){
				now=dp[i][0]-dp[k][0]*p(i-k);
				dp[i][j]=max(dp[i][j],dp[k][j-1]*now);
				}
			}
		}
	cout<<dp[N][K]<<endl;
	return 0;
	}

