//POJ P1273 Drainae Ditches
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define INF 999999999
using namespace std;
long long g[205][205]={0};
int layer[205]={0};
int N,M;
bool get_layer(){
    memset(layer,0,sizeof(layer));
    queue<int> q;
    q.push(1);
    layer[1]=1;
    while(!q.empty()){
        int top=q.front();
        for(int i=1; i<=N; i++)
            if(g[top][i]>0&&layer[i]==0){
                layer[i]=layer[top]+1;
                q.push(i);
            }
        q.pop();
    }
    return 0;
}
long long dfs(int u,int v,long long maxf){
    if(u==v) return maxf;
    long long ret=0;
    for(int i=1; i<=N; i++){
        if(layer[i]=layer[u]+1&&g[u][i]>0){
            long long Min=min(maxf-ret,g[u][i]);
            long long f=dfs(i,v,Min);
            g[u][i]-=f;
            g[i][u]+=f;
            ret+=f;
            if(ret==maxf) return ret;
        }
    }
    return ret;
}
int main(){
    int a,b;
    long long c;
    scanf("%d %d",&N,&M);
    for(int i=1; i<=N; i++){
        scanf("%d %d %lld",&a,&b,&c);
        g[a][b]+=c;
    }
    long long ans=0;
    while(get_layer()) ans+=dfs(1,M,INF);
    printf("%lld\n",ans);
    return 0;
}