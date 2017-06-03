//CodeVS P1098 ¾ù·ÖÖ½ÅÆ 
#include <iostream>
using namespace std;
int a[105]={0},le[105]={0},ri[105]={0};
int main(){
	int N,sum=0,ans=0;
	cin>>N;
	for(int i=1; i<=N; i++){
		cin>>a[i];
		sum+=a[i];
		}
	sum/=N;
	for(int i=1; i<=N; i++){
		a[i]-=sum;
		le[i]=le[i-1]+a[i];
		}
	for(int i=N; i>=1; i--) ri[i]=ri[i+1]+a[i];
	if(a[1]>0){
		ans++;
		a[2]+=a[1];
		ri[2]+=a[1];
		a[1]=0;
		le[1]=0;
		}
	if(a[N]>0){
		ans++;
		a[N-1]+=a[N];
		le[N-1]+=a[N];
		a[N]=0;
		ri[N]=0;
		}
	while(1){
		int i=2;
		while(a[i]<=0&&i<=N-1) i++;
		if(i==N) break;
		if(le[i-1]<0){
			ans++;
			a[i-1]+=-le[i-1];
			le[i-1]=0;
			}
		if(ri[i+1]<0){
			ans++;
			a[i+1]+=-ri[i];
			ri[i+1]=0;
			}
		a[i]=0;
		le[i]=0;
		ri[i]=0;
		}
	cout<<ans<<endl;
	return 0;
	}
