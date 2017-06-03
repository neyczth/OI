//UOJ P0282 长度测量鸡
#include <cstdio>
#include <cstring>
using namespace std;
bool vst[2505]={0},used[2505*2505]={0},flag=0;
int a[2505]={0},N;
long long sum[2505]={0};
bool check(){
    memset(used,0,sizeof(used));
    sum[0]=0;
    for(int i=1; i<=N; i++) sum[i]=sum[i-1]+a[i];
    for(int i=0; i<=N; i++){
        for(int j=i+1; j<=N; j++){
            if(used[sum[j]-sum[i]]) return false;
            used[sum[j]-sum[i]]=1;
        }
    }
    return true;
}
void trace(int n){
    if(n==N+1) flag=check();
    if(flag==1) return;
    for(int i=1; i<=N; i++){
        if(!vst[i]){
            a[n]=i;
            vst[i]=1;
            trace(n+1);
            vst[i]=0;
            a[n]=0;
        }
    }
    return;
}
int main(){
    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        flag=0;
        memset(vst,0,sizeof(vst));
        trace(1);
        if(flag==1) printf("Yes!\n");
        else printf("No!\n");
    }
    return 0;
}