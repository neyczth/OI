//洛谷 P1102 A-B数对
#include <cstdio>
using namespace std;
int cnt[2000005]={0};
int main(){
    int n,c,x;
    scanf("%d %d",&n,&c);
    c < 0 ? c = -c : c=c;
    for(int i=1; i<=n; i++){
        scanf("%d",&x);
        cnt[x]++;
    }
    long long ans=0;
    for(int i=1; i<=n-c; i++) ans+=cnt[i]*cnt[i+c];
    printf("%lld\n",ans);
    return 0;
}