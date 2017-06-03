//洛谷 U5927 Pass的影子游戏
#include <cstdio>
#include <cmath>
using namespace std;
int a[100005]={0},ans[100005]={0};
int vst[1000005]={0};
int main(){
	int N;
	scanf("%d",&N);
	for(int i=1; i<=N; i++){
		scanf("%d",&a[i]);
		vst[a[i]]++;
		}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=sqrt(a[i]); j++){
			if(a[i]%j!=0) continue;
			if(j==sqrt(a[i])) ans[i]+=vst[j];
			else ans[i]+=vst[j]+vst[a[i]/j];
			}
		}
	for(int i=1; i<=N; i++) ans[i]--;
	for(int i=2; i<=N; i++) if(a[i]%a[1]==0) ans[i]--;
	for(int i=1; i<=N; i++) printf("%d\n",ans[i]);
	return 0;
	}
