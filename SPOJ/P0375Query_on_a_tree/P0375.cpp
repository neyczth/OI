//SPOJ P0375 Query on a tree
#include <bits/stdc++.h>
using namespace std;
int end[20005]={0},last[10005]={0},prev[20005]={0},cost[20005]={0};
int son[10005]={0},size[10005]={0},fa[10005]={0};
int rank[10005]={0},id;
bool vst[10005]={0};
map<pair<int,int>,int> m;
void dfs1(int now){//第一次DFS找到每个节点的重儿子, 记录每个节点子树的size.
    int edge=last[now];
    while(edge){
        if(!vst[end[edge]]){
            vst[end[edge]]=1;
            dfs1(end[edge]);
            size[now]+=size[end[edge]];
            if(size[end[edge]]>size[son[now]]) son[now]=end[edge];
        }
        edge=prev[edge];
    }
    size[end[edge]]++;
    return;
}
void dfs2(int now){//第二次DFS为边标记顺序, 找到重fa, 准备形成线段树.
    if(son[now]) rank[++id]=m[make_pair(now,son[now])];
    dfs2(son[now]);//率先遍历重儿子.
    fa[son[now]]=now;
    int edge=last[now];
    while(edge){
        int v=end[edge];
        if(v!=son[now]){
            dfs2(v);
            fa[v]=v;
        }
        edge=prev[edge];
    }
    return;
}
int main(){
    freopen("input.txt","r",stdin);
    int T,N,a,b,c;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=1; i<N; i++){
            scanf("%d %d %d",&a,&b,&c);
            end[2*i-1]=b;
            prev[2*i-1]=last[a];
            last[a]=2*i-1;
            cost[2*i-1]=c;
            m.insert(make_pair(make_pair(a,b),2*i-1));
            end[2*i]=a;
            prev[2*i]=last[b];
            last[b]=2*i;
            cost[2*i]=c;
            m.insert(make_pair(make_pair(b,a),2*i));
        }
        dfs1(1);
        id=0;
        fa[1]=1;
        dfs2(1);
    }
}