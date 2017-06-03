//CodeVS P2602 最短路径问题
#include <bits/stdc++.h>
using namespace std;
bool g[105][105]={0};
bool vst[105]={0};
double dis[105]={0};
struct point{
    int x,y;
}p[105];
double dist(int a,int b){
    int x=p[a].x-p[b].x,y=p[a].y-p[b].y;
    return sqrt(x*x+y*y);
}
int main(){
    int N,M,a,b,s,t;
    scanf("%d",&N);
    for(int i=1; i<=N; i++){
        scanf("%d %d",&a,&b);
        p[i].x=a;
        p[i].y=b;
    }
    scanf("%d",&M);
    for(int i=1; i<=M; i++){
        scanf("%d %d",&a,&b);
        g[a][b]=1;
        g[b][a]=1;
    }
    scanf("%d %d",&s,&t);
    queue<int> q;
    for(int i=1; i<=N; i++) dis[i]=0x3F3F3F3F;
    q.push(s);
    vst[s]=1;
    dis[s]=0;
    while(!q.empty()){
        int now=q.front();
        for(int i=1; i<=N; i++){
            if(g[now][i]&&dis[now]+dist(now,i)<dis[i]){
                if(!vst[i]){
                    vst[i]=1;
                    q.push(i);
                }
                dis[i]=dis[now]+dist(now,i);
            }
        }
        vst[now]=0;
        q.pop();
    }
    printf("%.2lf\n",dis[t]);
    return 0;
}